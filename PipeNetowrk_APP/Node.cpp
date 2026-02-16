#include"Node.hpp"
namespace cie
{
	namespace pipenetwork
	{

		Node::Node(double x, double y, double flow, int id)
		{
			x_ = x;
			y_ = y;
			flow_ = flow;
			id_ = id;
			Head_ = 0;
		}

		Node::Node()
		{
			x_ = 0;
			y_ = 0;
			flow_ = 0;
			id_ = 0;
			Head_ = 0;
		}

		double Node::x() const
		{
			return x_;
		}

		double Node::y() const
		{
			return y_;
		}

		double Node::flow() const
		{
			return flow_;
		}

		int Node::id() const
		{
			return id_;
		}

		void Node::Set_Head_Value(double value)
		{
			Head_ = value;
		}

		double Node::Get_Head() const
		{
			return Head_;
		}
		
	   } // namespace PipeNetowrk
}     // namespace cie