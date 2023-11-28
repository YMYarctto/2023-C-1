# 2023 C语言期中
```
#include <stdio.h>

//主菜单页面
void mainMenu();
//查看成绩菜单页面
void scoreMenu();
//返回用户输入的数字，1~max为有效
int scanln(int max);
//主菜单页面显示后执行输入逻辑，传入数组
void mainMenuInput(int *stu);
//查看成绩页面显示后执行输入逻辑，传入数组
void scoreMenuInput(int *stu, int size);
//输入成绩并存入数组，传入数组
void inputScore(int *stu);
//交换元素，传入数组和偏移量，在IntSort中使用
void changeElement(int *arr, int i, int offset);
//排序并交换整行，传入数组和排序列
void IntSort(int *arr, int size, int input);
//输出成绩，传入数组
void outputScore(int *stu, int size);
//执行查找逻辑，传入数组
void search(int *stu, int size);
//计算平均分，传入数组
void Cal(int *stu, int size);

int main() {
	int students[30][5] = {};
	mainMenu();
	mainMenuInput(&students[0][0]);
	return 0;
}

void mainMenu() {
	printf("|------------------------|\n");
	printf("|---学生成绩统计系统-----|\n");
	printf("|------------------------|\n");
	printf("|---1.查看学生成绩-------|\n");
	printf("|---2.输入学生成绩-------|\n");
	printf("|---3.查找学生成绩-------|\n");
	printf("|---4.计算平均分---------|\n");
	printf("|---5.退出系统-----------|\n");
	printf("|------------------------|\n\n");
}

void scoreMenu() {
	printf("\n|------------------------|\n");
	printf("|---1.按学号查看---------|\n");
	printf("|---2.按数学成绩查看-----|\n");
	printf("|---3.按英语成绩查看-----|\n");
	printf("|---4.按物理成绩查看-----|\n");
	printf("|---5.按总分查看---------|\n");
	printf("|---6.返回上级-----------|\n");
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
					printf("已达到人数上限\n");
				}
				break;
			case 3:
				search(stu, size);
				break;
			case 4:
				Cal(stu, size);
				break;
			case 5:
				printf("\n感谢您的使用，下次再见");
				return;
			default:
				printf("错误输入\n");
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
				printf("|--已返回到上级--|\n");
				printf("|----------------|\n\n");
				return;
			default:
				printf("错误输入\n");
				break;
		}
	}
}

void inputScore(int *stu) {
	printf("请输入以下数据：学号，数学成绩，英语成绩，物理成绩(用英文逗号隔开)\n");
	while (1) {
		printf(">>");
		if (scanf("%d,%d,%d,%d", &stu[0], &stu[1], &stu[2], &stu[3]) != 4) {
			while (getchar() != '\n');
			printf("错误输入\n\n");
		} else {
			stu[4] = stu[1] + stu[2] + stu[3];
			printf("输入成功\n\n");
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
	printf("|      学号 数学成绩 英语成绩 物理成绩 总成绩|\n");
	for (int i = 0; i < size; i++) {
		printf("|%10d   %3d      %3d      %3d      %3d |\n", stu[i * 5], stu[i * 5 + 1], stu[i * 5 + 2], stu[i * 5 + 3],
		       stu[i * 5 + 4]);
	}
	printf("|--------------------------------------------|\n\n");
}

void search(int *stu, int size) {
	printf("请输入要查找学生的学号\n>");
	int num = scanln((int)1e11);
	for (int i = 0; i < size; i++) {
		if (stu[i * 5] == num) {
			printf("\n已找到学号为%d的学生的成绩\n", num);
			printf("|-----------------------------------|\n");
			printf("| 数学成绩 英语成绩 物理成绩 总成绩 |\n");
			printf("|   %3d      %3d      %3d      %3d  |\n", stu[i * 5 + 1], stu[i * 5 + 2], stu[i * 5 + 3], stu[i * 5 + 4]);
			printf("|-----------------------------------|\n\n");
			return;
		}
	}
	printf("未找到学号\n\n", num);
}

void Cal(int *stu, int size) {
	if (size == 0) {
		printf("暂无数据\n\n");
		return;
	}
	double count[4] = {};
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < size; j++) {
			count[i - 1] += stu[5 * j + i];
		}
		count[i - 1] /= size;
	}
	printf("\n该班级平均分如下\n");
	printf("|--------------------------------------|\n");
	printf("| 数学成绩  英语成绩  物理成绩  总成绩 |\n");
	printf("|  %6.2lf    %6.2lf    %6.2lf   %6.2lf |\n", count[0], count[1], count[2], count[3]);
	printf("|--------------------------------------|\n\n");
}
```