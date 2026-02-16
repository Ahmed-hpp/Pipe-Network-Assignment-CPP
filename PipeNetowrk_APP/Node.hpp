#pragma once

namespace cie
{
	namespace pipenetwork
	{
		class Node
		{
		public:
			Node(double x, double y, double flow, int id);

			Node();

			double x() const;

			double y() const;

			double flow() const;

			int id()const;

			void Set_Head_Value(double value);

			double Get_Head() const;


		private:
			double x_, y_, flow_;
			int id_;
			double Head_;
		};

	}// namespace PipeNetowrk
	}     // namespace cie