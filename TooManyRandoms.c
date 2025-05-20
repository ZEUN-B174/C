#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

char name[20]; // �÷��̾� �̸�
int randomNumber = 0; // ���� ����
int deathCount = 0; // ��� Ƚ��

int getRandomNumber(int min, int max);
void mainGame();
void gameOver();
void wait(float seconds);

int main() {
	int choice = 0;
	char titleVariation[3][72] = {
		"������ �ʹ� ���� RPG...���� ��ư�� ������ �ƴ϶� ����������...",
		"������ �ʹ� ���� RPG, �ʹ� �� ���Ѱ�?",
		"������ �ʹ� ���� RPG - �� �޽����� ��� Ƚ���� 10�� ����϶� ���´�ϴ�"
	};

	if (deathCount % 10 == 0 && deathCount != 0) {
		randomNumber = getRandomNumber(0, 2); // 0, 1, 2 �� �������� ����
		printf("%s\n", titleVariation[randomNumber]);
	}
	else {
		printf("������ �ʹ� ���� RPG\n");
	}
	printf("1. �����ϱ�\n2. �׸��ϱ�\n�� ");
	scanf_s("%d", &choice);
	if (choice == 1) {
		mainGame();
	}
	else {
		printf("\n������ �����մϴ�.\n");
		exit(0); // ���α׷� ����
	}
}

int getRandomNumber(int min, int max) {
	srand(time(NULL)); // �õ� ����
	return (rand() % (max - min + 1)) + min;
}

void mainGame() {
	printf("\n���� �����ϱ⿡ �ռ�, ����� �̸��� �Է��ϼ���\n�� ");
	scanf_s("%s", name, sizeof(name)); // �÷��̾� �̸� �Է�
	randomNumber = getRandomNumber(1, 10);
	// printf("%d\n", randomNumber); // ����׿� ���� ���� ���
	if (randomNumber <= 3) {
		printf("\n����� �ڽ��� �̸��� �Է��ϴٰ� �ǹ��� ���� ���� ����߽��ϴ�.\n");
		wait(1.7);
		printf("�ƴ� �����ϱ⵵ ���� �״°� ����\n");
		wait(1.7);
		gameOver();
	}
	printf("����� %s�̶�� �̸��� ������ �Է��߽��ϴ�.\n", name);
	wait(1.7);
	printf("�̸��� ������ �Է�������, ���� ������ ���� ��� ������ ���ô�.\n");
	wait(1.7);
	randomNumber = getRandomNumber(1, 10);
	// printf("%d\n", randomNumber); // ����׿� ���� ���� ���

	if (randomNumber >= 9) {
		printf("\n��� ������ ���� �濡, ����� ���� �Ҿ����ϴ�.\n");
		wait(1.7);
		printf("�̷�! �׷� ����� �տ� ���ù����� ������ ��Ÿ�����ϴ�!\n");
		wait(1.7);
		printf("����� �վ� ���� ���� �������� ����� �Ұ� ���ҽ��ϴ�...\n");
		wait(1.7);
		gameOver();
	}

	printf("\n");
	main();
}

void gameOver() {
	printf("\n���� ����\n\n==========================================\n\n");
	deathCount++;
	main();
}

void wait(float seconds) {
	Sleep((int)seconds * 1000); // seconds�� �и��ʷ� ��ȯ�Ͽ� ���
}