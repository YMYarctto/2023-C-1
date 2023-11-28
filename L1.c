#include <stdio.h>

//���˵�ҳ��
void mainMenu();
//�鿴�ɼ��˵�ҳ��
void scoreMenu();
//�����û���������֣�1~maxΪ��Ч
int scanln(int max);
//���˵�ҳ����ʾ��ִ�������߼�����������
void mainMenuInput(int *stu);
//�鿴�ɼ�ҳ����ʾ��ִ�������߼�����������
void scoreMenuInput(int *stu, int size);
//����ɼ����������飬��������
void inputScore(int *stu);
//����Ԫ�أ����������ƫ��������IntSort��ʹ��
void changeElement(int *arr, int i, int offset);
//���򲢽������У����������������
void IntSort(int *arr, int size, int input);
//����ɼ�����������
void outputScore(int *stu, int size);
//ִ�в����߼�����������
void search(int *stu, int size);
//����ƽ���֣���������
void Cal(int *stu, int size);

int main() {
	int students[30][5] = {};
	mainMenu();
	mainMenuInput(&students[0][0]);
	return 0;
}

void mainMenu() {
	printf("|------------------------|\n");
	printf("|---ѧ���ɼ�ͳ��ϵͳ-----|\n");
	printf("|------------------------|\n");
	printf("|---1.�鿴ѧ���ɼ�-------|\n");
	printf("|---2.����ѧ���ɼ�-------|\n");
	printf("|---3.����ѧ���ɼ�-------|\n");
	printf("|---4.����ƽ����---------|\n");
	printf("|---5.�˳�ϵͳ-----------|\n");
	printf("|------------------------|\n\n");
}

void scoreMenu() {
	printf("\n|------------------------|\n");
	printf("|---1.��ѧ�Ų鿴---------|\n");
	printf("|---2.����ѧ�ɼ��鿴-----|\n");
	printf("|---3.��Ӣ��ɼ��鿴-----|\n");
	printf("|---4.������ɼ��鿴-----|\n");
	printf("|---5.���ֲܷ鿴---------|\n");
	printf("|---6.�����ϼ�-----------|\n");
	printf("|------------------------|\n\n");
}

int scanln(int max) {
	int input;
	printf(">");
	if (scanf("%d", &input) != 1) {
		while (getchar() != '\n');
		return -1;
	} else if (input < 1 || input > max) {
		return -1;
	}
	return input;
}

void mainMenuInput(int *stu) {
	int size = 0;
	while (1) {
		switch (scanln(5)) {
			case 1:
				scoreMenu();
				scoreMenuInput(stu, size);
				break;
			case 2:
				if (size < 30) {
					inputScore(&stu[5 * size]);
					size += 1;
				} else {
					printf("�Ѵﵽ��������\n");
				}
				break;
			case 3:
				search(stu, size);
				break;
			case 4:
				Cal(stu, size);
				break;
			case 5:
				printf("\n��л����ʹ�ã��´��ټ�");
				return;
			default:
				printf("��������\n");
				break;
		}
	}
}

void scoreMenuInput(int *stu, int size) {
	while (1) {
		printf(">");
		int input = scanln(6);
		switch (input) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				IntSort(stu, size, input - 1);
				outputScore(stu, size);
				break;
			case 6:
				printf("\n|----------------|\n");
				printf("|--�ѷ��ص��ϼ�--|\n");
				printf("|----------------|\n\n");
				return;
			default:
				printf("��������\n");
				break;
		}
	}
}

void inputScore(int *stu) {
	printf("�������������ݣ�ѧ�ţ���ѧ�ɼ���Ӣ��ɼ�������ɼ�(��Ӣ�Ķ��Ÿ���)\n");
	while (1) {
		printf(">>");
		if (scanf("%d,%d,%d,%d", &stu[0], &stu[1], &stu[2], &stu[3]) != 4) {
			while (getchar() != '\n');
			printf("��������\n\n");
		} else {
			stu[4] = stu[1] + stu[2] + stu[3];
			printf("����ɹ�\n\n");
			return;
		}
	}
}

void changeElement(int *arr, int i, int offset) {
	int temp;
	temp = arr[i * 5 + offset];
	arr[i * 5 + offset] = arr[(i + 1) * 5 + offset];
	arr[(i + 1) * 5 + offset] = temp;
}

void IntSort(int *arr, int size, int input) {
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size - 1 - j; i++) {
			if (arr[i * 5 + input] < arr[(i + 1) * 5 + input]) {
				for (int k = 0; k < 5; k++) {
					changeElement(arr, i, k);
				}
			}
		}
	}
}

void outputScore(int *stu, int size) {
	printf("\n|--------------------------------------------|\n");
	printf("|      ѧ�� ��ѧ�ɼ� Ӣ��ɼ� ����ɼ� �ܳɼ�|\n");
	for (int i = 0; i < size; i++) {
		printf("|%10d   %3d      %3d      %3d      %3d |\n", stu[i * 5], stu[i * 5 + 1], stu[i * 5 + 2], stu[i * 5 + 3],
		       stu[i * 5 + 4]);
	}
	printf("|--------------------------------------------|\n\n");
}

void search(int *stu, int size) {
	printf("������Ҫ����ѧ����ѧ��\n>");
	int num = scanln((int)1e11);
	for (int i = 0; i < size; i++) {
		if (stu[i * 5] == num) {
			printf("\n���ҵ�ѧ��Ϊ%d��ѧ���ĳɼ�\n", num);
			printf("|-----------------------------------|\n");
			printf("| ��ѧ�ɼ� Ӣ��ɼ� ����ɼ� �ܳɼ� |\n");
			printf("|   %3d      %3d      %3d      %3d  |\n", stu[i * 5 + 1], stu[i * 5 + 2], stu[i * 5 + 3], stu[i * 5 + 4]);
			printf("|-----------------------------------|\n\n");
			return;
		}
	}
	printf("δ�ҵ�ѧ��\n\n", num);
}

void Cal(int *stu, int size) {
	if (size == 0) {
		printf("��������\n\n");
		return;
	}
	double count[4] = {};
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < size; j++) {
			count[i - 1] += stu[5 * j + i];
		}
		count[i - 1] /= size;
	}
	printf("\n�ð༶ƽ��������\n");
	printf("|--------------------------------------|\n");
	printf("| ��ѧ�ɼ�  Ӣ��ɼ�  ����ɼ�  �ܳɼ� |\n");
	printf("|  %6.2lf    %6.2lf    %6.2lf   %6.2lf |\n", count[0], count[1], count[2], count[3]);
	printf("|--------------------------------------|\n\n");
}