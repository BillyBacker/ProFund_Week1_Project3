#include<stdio.h>

int Matrix_show(float Array[9]) {
	for (int ele_num = 0; ele_num < 9; ele_num+=3) {
		printf("| ");
		printf("%.2f %.2f %.2f ", Array[ele_num], Array[ele_num+1], Array[ele_num+2]);
		printf("|\n");
	}
	return 0;
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
	transpose(Matrix2);
	Matrix_show(buffer);
}

void plus(float Matrix1[9], float Matrix2[9]) {
	float buffer[9];
	for (int Index = 0; Index < 9; Index++){
		buffer[Index] = Matrix1[Index] + Matrix2[Index];
	}
	Matrix_show(buffer);
}

int main() {
	float Out[9];
	float In1[9];
	float In2[9];

	printf("Matrix calculator\n");
	printf("Input example :\n| 1 2 3\n| 4 5 6\n| 7 8 9\n\n");

	printf("Enter Matrix A : \n");
	for (int Ele_num = 0; Ele_num < 9; Ele_num += 3) {
		printf("| ");
		scanf_s("%f %f %f", &In1[Ele_num], &In1[Ele_num+1], &In1[Ele_num+2]);
	}

	printf("Enter Matrix B : \n");
	for (int Ele_num = 0; Ele_num < 9; Ele_num += 3) {
		printf("| ");
		scanf_s("%f %f %f", &In2[Ele_num], &In2[Ele_num + 1], &In2[Ele_num + 2]);
	}
	printf("\nA Transpose\n");
	transpose(In1);
	Matrix_show(In1);
	transpose(In1);
	printf("\nB Transpose\n");
	transpose(In2);
	Matrix_show(In2);
	transpose(In2);
	printf("\nA + B\n");
	plus(In1, In2);
	transpose(In2);
	printf("\nA dot B\n");
	dot(In1, In2);
	
}