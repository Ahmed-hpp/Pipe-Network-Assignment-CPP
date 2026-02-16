#include<iostream>
#include"PipeNetWork.hpp"


int main()
{
	
	std::cout << "Welcome to my small Program to do some calculations for PipeNetworks " << std:: endl;
	std::cout << "Please make sure to include the data of the PipeNetowrk in file.txt " << std::endl;
	std::cout << "Type the name of the Data file " << std::endl;
	std::string name;
	std::cin >> name;
	cie::pipenetwork::PipeNetwork net1(name);

	std::cout << " Choose one option : " << std::endl;
	std::cout << " 1-Print fluxes of Tubes on the screen " << std::endl;
	std::cout << " 2-Print Heads of Nodes on the screen " << std::endl;
	std::cout << " 3-Write fluxes and heads in external text file " << std::endl;
	
	int op;
	std::cin >> op;
	switch (op)
	{
	case 1 :
		net1.print_flux();
		break;

	case 2 :
		net1.Head_print();
		break;
	
	case 3:
		net1.Write_Result_Data();
		break;


	default:
		break;
	}


	



}