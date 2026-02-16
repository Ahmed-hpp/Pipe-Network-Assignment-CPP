#include"PipeNetWork.hpp"



namespace cie
{
	namespace pipenetwork
	{
		PipeNetwork::PipeNetwork(std::string& const filename)
		{
			std::ifstream infile(filename);
			int Nodes_Number, Tubes_Number;
			infile >> Nodes_Number >> Tubes_Number;

			nodes.reserve(Nodes_Number);
			tubes.reserve(Tubes_Number);
			Q_flow.reserve(Nodes_Number);
			H_Values.reserve(Nodes_Number);

			
			for (int i = 0; i < Nodes_Number; ++i)
			{
				double x, y, flow;
				infile >> x >> y >> flow;
				Node TemporaryNode(x, y, flow, i);
				nodes.push_back(TemporaryNode);

			}
			
			for (int i = 0; i < Tubes_Number; ++i)
			{
				int first_nodeID, second_nodeID;
				double diameter;
				infile >> first_nodeID >> second_nodeID >> diameter;

				Tube TemporaryTube(&nodes[first_nodeID], &nodes[second_nodeID], diameter);
				tubes.push_back(TemporaryTube);

			}
			

			 
			cie::linalg::Matrix Mat  (Nodes_Number, Nodes_Number, 0);

			for (int i = 0; i < Nodes_Number; ++i)
			{
				for (int j = 0; j < Nodes_Number; ++j)

				{
					Mat(i, j) = Extract_Mat_Diagonal(i, j);
				}
			}

			for (int i = 0; i < Nodes_Number; ++i)
			{
				for (int j = 0; j < Nodes_Number; ++j)
				{
					if (i != j)
					{
						Mat(i, j) = Extract_non_Diagonal(i, j); 
					}
				}
			}


			for (int i = 0; i < Nodes_Number; ++i)
			{
				for (int j = 0; j < Nodes_Number; ++j)
				{
					Mat(0, j) = 0;
					Mat(j, 0) = 0;
				}

			}

			Mat(0, 0) = 1;                     


			
			for (int i = 0; i < nodes.size(); ++i)
			{
				double value;
				value = nodes[i].flow();
				Q_flow.push_back(value);


			}

			Q_flow[0] = 0; 

			B_values = Get_B_values_Vector();

			H_Values = Head_calculation(Mat, Q_flow); 


			
			for (int i = 0; i < nodes.size(); ++i)
			{
				nodes[i].Set_Head_Value(H_Values[i]);
			}

			q_flux = computeFluxes();

			

		} 

		PipeNetwork::PipeNetwork()
		{

		}

		
		Node PipeNetwork::Show_Specific_node(int i) const // show specific node from the nodes vector
		{
			return nodes[i];
		}

		Tube PipeNetwork::Show_Specific_tube(int i) const // show specific node from the tubes vector
		{
			return tubes[i];
		}

		std::vector<double> PipeNetwork::Get_B_values_Vector() const // Extract the B values to a vector 
		{

			std::vector<double> x;
			for (int i = 0; i < tubes.size(); ++i)
			{
				double value;
				value = tubes[i].permeability();
				x.push_back(value);
			}

			return x;
		}

		double PipeNetwork::Extract_Mat_Diagonal(int x, int y) //set diagonal entries of B_matrix
		{
			int bound1;     double Tube_Per = 0.0;
			int bound2;		double B = 0.0;
			for (int i = 0; i < tubes.size(); ++i)
			{
				bound1 = tubes[i].Get_Node1_Id();
				bound2 = tubes[i].Get_Node2_Id();
				Tube_Per = tubes[i].permeability();
				if (x == y && (x == bound1 || y == bound2))
				{
					B += Tube_Per;
				}
			}
			return B;
		}

		double PipeNetwork::Extract_non_Diagonal(int x, int y) //set non-diagonal entries of B_matrix
		{
			int bound1;     double z = 0;
			int bound2;       double B = 0.0;
			for (int i = 0; i < tubes.size(); ++i)
			{
				bound1 = tubes[i].Get_Node1_Id();
				bound2 = tubes[i].Get_Node2_Id();
				z = tubes[i].permeability();
				if (bound1 == x && bound2 == y)
				{
					B = -z;
				}
				else if (bound1 == y && bound2 == x)
				{
					B = -z;
				}
			}

			return B;
		}

		void PipeNetwork::Matrix_Print() const  // print matrix on screen
		{
			for (int i = 0; i < nodes.size(); ++i)
			{
				std::cout << " \n [ ";
				for (int j = 0; j < nodes.size(); ++j)
				{
					std::cout << Mat(i, j) << "  ,  ";
				}
				std::cout << " ]\n\n ";
			}
		}

		
		std::vector<double> PipeNetwork::Head_calculation(cie::linalg::Matrix& B_Matrix, std::vector<double>& Q_vector)
		{   
			return cie::linalg::solve(B_Matrix, Q_vector);
		}

		void PipeNetwork::Head_print() const 
		{
			for (int i = 0; i < nodes.size(); ++i)
			{
				std::cout <<"Head in Node " << i <<"  =  " << H_Values[i] << std::endl;
			}
		}

		void PipeNetwork::Insert_Head_values_To_Nodes() // insert each head to its node
		{
			for (int i = 0; i < nodes.size(); ++i)
			{
				nodes[i].Set_Head_Value(H_Values[i]);
			}
		}

		std::vector<double> PipeNetwork::computeFluxes() const // compute flux in each pipe
		{
			std::vector<double>x;
			for (int i = 0; i < tubes.size(); ++i)
			{
				double t = B_values[i] * (tubes[i].node2()->Get_Head() - tubes[i].node1()->Get_Head());
				x.push_back(t);
			}
			return x;
		}

		void PipeNetwork::print_flux() const // print flux on screen
		{
			for (int i = 0; i < tubes.size(); ++i)
			{
				std::cout <<"Flux in Tube " <<i<<" = " << q_flux[i] << std::endl;
			}
		}


		void PipeNetwork::Write_Result_Data() const
		{
			std::ofstream Flux_Results;
			Flux_Results.open("Results.txt");


			for (int i = 0; i < nodes.size(); ++i)
			{
				Flux_Results << " Head in node " << i << "  =  " << nodes[i].Get_Head() << "\n";
			}
			Flux_Results << "\n=========================\n\n ";

			for (int i = 0; i < tubes.size(); ++i)
			{
				Flux_Results << " Flux in Tube " << i << "  =   " << q_flux[i] << "\n";
				
			}
			Flux_Results.close();
		}

		
	

	}// namespace PipeNetowrk


} //namespace cie
