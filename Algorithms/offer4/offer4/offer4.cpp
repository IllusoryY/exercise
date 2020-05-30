/*
题目：二维数组中的查找
	在一个二维数组中，每一行都是按照从左到右递增的顺序排序，每一列都是按照从上到下递增的顺序排序。
	请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

bool find(int* matrix, int rows, int columns, int number)
{
	bool found = false;

	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			int tmp = matrix[row * columns + column];
			if (tmp == number)
			{
				found = true;
				break;
			}
			else if (tmp > number)
				--column;
			else
				++row;
		}
	}
	return found;
}