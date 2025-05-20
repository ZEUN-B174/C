#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

char name[20]; // 플레이어 이름
int randomNumber = 0; // 랜덤 숫자
int deathCount = 0; // 사망 횟수

int getRandomNumber(int min, int max);
void mainGame();
void gameOver();
void wait(float seconds);

int main() {
	int choice = 0;
	char titleVariation[3][72] = {
		"랜덤이 너무 많은 RPG...시작 버튼은 랜덤이 아니라 다행일지도...",
		"랜덤이 너무 많은 RPG, 너무 억까가 심한가?",
		"랜덤이 너무 많은 RPG - 이 메시지는 사망 횟수가 10의 배수일때 나온답니다"
	};

	if (deathCount % 10 == 0 && deathCount != 0) {
		randomNumber = getRandomNumber(0, 2); // 0, 1, 2 중 랜덤으로 선택
		printf("%s\n", titleVariation[randomNumber]);
	}
	else {
		printf("랜덤이 너무 많은 RPG\n");
	}
	printf("1. 시작하기\n2. 그만하기\n▶ ");
	scanf_s("%d", &choice);
	if (choice == 1) {
		mainGame();
	}
	else {
		printf("\n게임을 종료합니다.\n");
		exit(0); // 프로그램 종료
	}
}

int getRandomNumber(int min, int max) {
	srand(time(NULL)); // 시드 설정
	return (rand() % (max - min + 1)) + min;
}

void mainGame() {
	printf("\n먼저 시작하기에 앞서, 당신의 이름을 입력하세요\n▶ ");
	scanf_s("%s", name, sizeof(name)); // 플레이어 이름 입력
	randomNumber = getRandomNumber(1, 10);
	// printf("%d\n", randomNumber); // 디버그용 랜덤 숫자 출력
	if (randomNumber <= 3) {
		printf("\n당신은 자신의 이름을 입력하다가 의문의 힘에 의해 사망했습니다.\n");
		wait(1.7);
		printf("아니 시작하기도 전에 죽는건 뭐야\n");
		wait(1.7);
		gameOver();
	}
	printf("당신은 %s이라는 이름을 무사히 입력했습니다.\n", name);
	wait(1.7);
	printf("이름도 무사히 입력했으니, 이제 모험을 위한 장비를 얻으러 갑시다.\n");
	wait(1.7);
	randomNumber = getRandomNumber(1, 10);
	// printf("%d\n", randomNumber); // 디버그용 랜덤 숫자 출력

	if (randomNumber >= 9) {
		printf("\n장비를 얻으러 가는 길에, 당신은 길을 잃었습니다.\n");
		wait(1.7);
		printf("이런! 그런 당신의 앞에 무시무시한 괴물이 나타났습니다!\n");
		wait(1.7);
		printf("당신이 손쓸 새도 없이 괴물에게 목숨을 잃고 말았습니다...\n");
		wait(1.7);
		gameOver();
	}

	printf("\n");
	main();
}

void gameOver() {
	printf("\n게임 오버\n\n==========================================\n\n");
	deathCount++;
	main();
}

void wait(float seconds) {
	Sleep((int)seconds * 1000); // seconds를 밀리초로 변환하여 대기
}