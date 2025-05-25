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
void say(char ment[], float seconds);

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
	int choice = 0;
	printf("\n먼저 시작하기에 앞서, 당신의 이름을 입력하세요\n▶ ");
	scanf_s("%s", name, sizeof(name)); // 플레이어 이름 입력
	
	randomNumber = getRandomNumber(1, 10);
	if (randomNumber <= 3) {
		say("당신은 이름을 입력하다가 의문의 힘에 의해 사망했습니다.", 0);
		say("아니 시작하기도 전에 죽는건 뭐야", 0);
		gameOver();
	}
	
	printf("당신은 %s이라는 이름을 무사히 입력했습니다.\n", name);
	wait(1.7);
	say("이름도 무사히 입력했으니, 이제 모험을 위한 장비를 얻으러 갑시다.", 0);
	
	randomNumber = getRandomNumber(1, 10);
	// printf("%d\n", randomNumber); // 디버그용 랜덤 숫자 출력
	if (randomNumber >= 9) {
		say("\n장비를 얻으러 가는 길에, 당신은 길을 잃었습니다.", 0);
		say("이런! 그런 당신의 앞에 무시무시한 괴물이 나타났습니다!", 0);
		say("당신이 손쓸 새도 없이 괴물에게 목숨을 잃고 말았습니다...", 0);
		
		gameOver();
	}

	say("당신은 상점가로 무사히 도착했습니다.", 0);
	say("당신 앞에 3개의 상점이 놓여져 있네요.", 0);
	printf("\n1. 무기 상점\n2. 방어구 상점\n3. 아이템 상점\n\n어떤 상점에 가시겠습니까?\n▶ ");
	scanf_s("%d", &choice);

	if (choice < 1 || choice > 3) {
		say("내가 분명히 1, 2, 3중에 고르라고 했을텐데?", 0);
		say("잘못 선택했으니 죽어!", 0);

		gameOver();
	}
	else if (choice == 1) {
		say("\n무기 상점에 오신 것을 환영합니다!", 0);
		
		randomNumber = getRandomNumber(1, 10);
		if (randomNumber > 3 && randomNumber < 7) {
			say("당신은 무기 상점에서 무기를 고르다가 실수로 총을 쏴버렸습니다.", 0);
			say("총알이 이리저리 날아다니다 당신의 머리를 관통하며 당신은 사망했습니다...", 0);
			say("저런.", 0);

			gameOver();
		}
		else {
			say("무사히 무기를 구매하고 모험을 계속합니다.", 0);
		}
	}
	else if (choice == 2) {
		say("\n방어구 상점에 오신 것을 환영합니다!", 0);

		randomNumber = getRandomNumber(1, 10);
		if (randomNumber <= 2) {
			say("방어구를 고르다가 방어구가 너무 무거워서 쓰러졌습니다.", 0);
			say("그대로 탈진해서 사망...", 0);

			gameOver();
		}
		else {
			say("무사히 방어구를 구매하고 모험을 계속합니다.", 0);
		}
	}
	else if (choice == 3) {
		say("\n아이템 상점에 오신 것을 환영합니다!", 0);

		randomNumber = getRandomNumber(1, 10);
		if (randomNumber >= 7) {
			say("아이템을 고르다가 실수로 진열장에 있던 폭탄을 건드려 터뜨려버렸습니다.", 0);
			say("폭발에 휘말려 사망...", 0);
			say("...", 0);
			say("에엑따;;", 0);
			
			gameOver();
		}
		else {
			say("무사히 아이템을 구매하고 모험을 계속합니다.", 0);
		}
	}

	printf("\n");
	main();
}

void gameOver() {
	printf("\n게임 오버\n\n==========================================\n\n");
	deathCount++;
	main();
}

void say(char ment[], float seconds) {
	if (seconds == 0) {
		seconds = 1.7; // 기본 대기 시간 설정
	}
	printf("%s\n", ment);
	Sleep((int)seconds * 1000);

}

void wait(float seconds) {
	Sleep((int)seconds * 1000); // seconds를 밀리초로 변환하여 대기
}
