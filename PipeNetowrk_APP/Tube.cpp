#include"Tube.hpp"


namespace cie
{
  namespace pipenetwork
  {
 
  Tube::Tube(Node* node1, Node* node2, double diameter)
  {
  	node1_ = node1;
  	node2_ = node2;
  	diameter_ = diameter;
  }
  
  Tube::Tube()
  {
  	node1_ = nullptr;
  	node2_ = nullptr;
  	diameter_ = 0;
  
  }
  
  int Tube::Get_Node1_Id() const
  {
  	return node1_->id();
  }
  
  int Tube::Get_Node2_Id() const
  {
  	return node2_->id();
  }
  
  double Tube::length() const
  {
  	double l = sqrt(pow(node1_->x() - node2_->x(), 2) + pow(node1_->y() - node2_->y(), 2));
  	return l;
  }
  
  double Tube::permeability() const
  {
      double pi = 3.14159265358979323846;
  	double B = (pi * 9.81 * pow(diameter_, 4)) / (128 * pow(10, -6) * length());
  	return B;
  }
  
  double Tube::diameter_get() const
  {
  	return diameter_;
  }
  
  const Node* Tube::node1() const
  {
  	return node1_;
  }
  
  const Node* Tube::node2() const
  {
  	return node2_;
  }

 }    // namespace PipeNetowrk
}     // namespace cie