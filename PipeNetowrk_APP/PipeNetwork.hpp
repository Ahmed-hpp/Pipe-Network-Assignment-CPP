#pragma once
#include"Node.hpp"
#include"Tube.hpp"
#include<algorithm>
#include<vector>
#include<fstream>
#include<iostream>
#include"linalg.hpp"





namespace cie 
{
	namespace pipenetwork
	{
		class PipeNetwork
		{
		public:
			PipeNetwork(std::string& const filename); 
			
			PipeNetwork();
			
			Node Show_Specific_node(int i)const; 

			Tube Show_Specific_tube(int i)const;

			std::vector<double> Get_B_values_Vector() const;

			double Extract_Mat_Diagonal(int x, int y);

			double Extract_non_Diagonal(int x, int y);   

			void Matrix_Print()const;


			std::vector<double> Head_calculation(cie::linalg::Matrix& B_Matrix, std::vector<double>& Q_vector); 


			void Head_print()const; 

			void Insert_Head_values_To_Nodes();


			std::vector<double> computeFluxes() const;

			void print_flux() const;

			void Write_Result_Data() const;





		private:

			std::vector<Node> nodes;
			std::vector<Tube> tubes;
			cie::linalg::Matrix Mat;
			std::vector<double> Q_flow;
			std::vector<double> H_Values;
			std::vector<double> q_flux;
			std::vector<double> B_values;
		};
	}// namespace PipeNetowrk
} // namespace cie