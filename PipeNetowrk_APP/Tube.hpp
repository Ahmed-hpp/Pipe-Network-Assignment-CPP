#pragma once
#include"Node.hpp"
#include<cmath>


namespace cie
{
	namespace pipenetwork
	{
		class Tube
		{
		public:
			Tube(Node* node1, Node* node2, double diameter);

			Tube();

			int Get_Node1_Id()const;

			int Get_Node2_Id()const;

			double length() const;

			double permeability() const;

			double diameter_get()const;

			const Node* node1()const;

			const Node* node2() const;

		private:
			Node* node1_;
			Node* node2_;
			double diameter_;
		};

	}   // namespace PipeNetowrk
}   //namespace cie