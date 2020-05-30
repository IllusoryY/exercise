/*
��Ŀ����ά�����еĲ���
	��һ����ά�����У�ÿһ�ж��ǰ��մ����ҵ�����˳������ÿһ�ж��ǰ��մ��ϵ��µ�����˳������
	�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
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