#include<stdio.h>

float sum(int Colum, int Row, float num, float Array2[3][3]) {
	float Out = num * Array2[Colum][Row];
	return Out;
}

int Matrix_show(float Array[9]) {
	for (int ele_num = 0; ele_num < 9; ele_num+=3) {
		printf("| ");
		printf("%.2f %.2f %.2f ", Array[ele_num], Array[ele_num+1], Array[ele_num+2]);
		printf("|\n");
	}
	return 0;
}

float cross_vector(float vector1[3], float vector2[3]) {
	float sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += vector1[i] * vector2[i];
	}
	return sum;
}

void transpose(float Matrix[9]) {
	float buffer[9];
	for (int I = 0; I < 9; I++) {
		if (I == 0 || I == 4 || I == 8) {
			buffer[I] = Matrix[I];
		}
		else if (I == 1 || I == 5) {
			float carry = buffer[I];
			buffer[I] = Matrix[I+2];
			buffer[I+2] = Matrix[I];
		}
		else if (I == 2) {
			float carry = buffer[I];
			buffer[I] = Matrix[I + 4];
			buffer[I + 4] = Matrix[I];
		}
	}
	for (int Index = 0; Index < 9; Index++) {
		Matrix[Index] = buffer[Index];
	}
}

void dot(float Matrix1[9], float Matrix2[9]) {
	transpose(Matrix2);
	float buffer[9];
	int buffer_Index;
	for (int M1_index = 0; M1_index < 3; M1_index++) {
		for (int M2_index = 0; M2_index < 3; M2_index++) {
			buffer_Index = (M1_index * 3) + (M2_index);
			buffer[buffer_Index] = (Matrix1[M1_index*3] * Matrix2[M2_index*3]) 
									+ (Matrix1[(M1_index*3) + 1] * Matrix2[(M2_index*3) + 1]) 
									+ (Matrix1[(M1_index*3) + 2] * Matrix2[(M2_index*3) + 2]);
		}
	}
	Matrix_show(buffer);
}

int main() {
	float Out[9];
	float In1[9];
	float In2[9];

	printf("Enter Matrix 1 : \n");
	for (int Ele_num = 0; Ele_num < 9; Ele_num += 3) {
		printf("| ");
		scanf_s("%f %f %f", &In1[Ele_num], &In1[Ele_num+1], &In1[Ele_num+2]);
	}

	printf("Enter Matrix 2 : \n");
	for (int Ele_num = 0; Ele_num < 9; Ele_num += 3) {
		printf("| ");
		scanf_s("%f %f %f", &In2[Ele_num], &In2[Ele_num + 1], &In2[Ele_num + 2]);
	}
	dot(In1, In2);
}