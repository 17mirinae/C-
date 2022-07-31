#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

void gotoxy(COORD pos);
void snaketest();
void draw();
int gameover(int, int, COORD head, COORD body[]);

#define EXT_CH 0xffffffe0
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define WIDTH 80
#define HEIGHT 40
#define BODY 10 //초기길이

int main(int argc, char* argv[])
{
	srand((unsigned)time(NULL));
	snaketest();

	return 0;
}
void gotoxy(COORD pos)
{
	HANDLE h;

	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, pos);
}
//if((q1<=y2&&q2>=y1)&&(p1<=x2&&p2>=x1)) 총돌처리


void snaketest()
{
	int over = 0, i, time;
	COORD head;
	COORD body[BODY];
	COORD place;
	int head_ix = 0; // 뱀의 몸통 배열 머리 위치
	int tail_ix = 0; //뱀의 몸통 배열 꼬리 위치
	int body_len = 0; //현재 뱀의 길이
	char key = RIGHT;


	//초기화
	head.X = 1;
	head.Y = 1;
	body[head_ix].X = head.X;
	body[head_ix].Y = head.Y;

	system("cls");
	draw();
	gotoxy(head);

	while (1)
	{
		Sleep(100);
		if (_kbhit())
		{
			//gotoxy(head);
			key = getchar();
			if (key == EXT_CH)
				key = getchar();
		}
		switch (key)
		{
		case UP:
			head.Y--;
			break;
		case DOWN:
			head.Y++;
			break;
		case LEFT:
			head.X--;
			break;
		case RIGHT:
			head.X++;
			break;
		case 'q': return;
		default: break;
		}
		gotoxy(head);
		printf("*");
		if (head_ix < BODY - 1)
		{
			head_ix++;	//머리가 몸통 배열의 끝까지 가지 않았을 경우
			body_len++;
		}
		else
		{
			head_ix = 0;	//머리가 몸통 배열 의 끝에 도달하면
			body_len++;		//인데스 헤드를 처음으로 되돌린다 링구조 현상
		}
		//새로운 지정된 몸통 배열의 위치에 머리 좌표 저장
		body[head_ix].X = head.X;
		body[head_ix].Y = head.Y;

		if (body_len >= BODY - 1)
		{
			gotoxy(body[tail_ix]);
			printf(" ");	//꼬리삭제

			//몸통 링 구조에서 꼬리 위치를 지정
			if (tail_ix < BODY - 1)
			{
				tail_ix++;
				body_len--; //몸통길이 감소
			}
			else
			{
				tail_ix = 0;
				body_len--;	//인데스 테일를 처음으로 되돌린다 링구조 현상
			}

		}

		if (gameover(head_ix, body_len, head, body) == 1)
		{
			break;
		}
		time = rand() % 20;

		place.X = (rand() % WIDTH - 2) + 1;
		place.Y = (rand() % HEIGHT - 2) + 1;
		if (time == 1)
		{
			while (place.X != 0 || place.Y != 0)
			{
				place.X = rand() % WIDTH - 2;
				place.Y = rand() % HEIGHT - 2;
			}
		}
		if ((time == 1) && ((place.X != head.X) && (place.Y != head.Y)))
		{

			gotoxy(place);
			printf("$");
		}




		if (key == 'q')
			break;
	}
}

void draw()
{
	int i;

	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	gotoxy(pos);

	for (i = 0; i < WIDTH; i++)
	{
		printf("-");
	}

	pos.X = 0; pos.Y = HEIGHT - 1;
	gotoxy(pos);

	for (i = 0; i < WIDTH; i++)
	{
		printf("-");
	}

	for (i = 1; i < HEIGHT - 1; i++)
	{
		pos.X = 0;
		pos.Y = i;
		gotoxy(pos);
		printf("|"); //왼쪽 벽
		pos.X = WIDTH - 1;
		gotoxy(pos);
		printf("|"); //오른쪽 벽
	}
}

int gameover(int head_ix, int body_len, COORD head, COORD body[])
{
	int i;

	for (i = 0; i < body_len; i++)
	{
		if (((head_ix != i) && (body[i].X == head.X)) && ((i != head_ix) && (body[i].Y == head.Y)))
		{
			return 1;
		}

	}

	if (head.X == 0 || head.X == WIDTH - 1)
	{
		gotoxy(head);
		printf("|");
		return 1;
	}
	if (head.Y == 0 || head.Y == HEIGHT - 1)
	{
		gotoxy(head);
		printf("-");
		return 1;
	}

	return 0;
}

/*
	if(kbhit()){   키입력이있을떄
		key = getch();
		if(key==EXT_CH)   확장키의 상위바이트 제외
			key = getch();
			 switch 문도 바꿔야함



			 COORD mana = {0,0};
			 mana.X = rand()%(WIDTH -2) + 1;
			 mana.Y = rand()%(HEIGHT -2 ) +1;
			 while(1)
			 if(rand()%20 == 0)
			 {
			 for(i=0;body_len;i++)
			 {
				if(mana.X == snake[i].X&&mana.Y==snake[i].Y)
				{
						overlap = 1;
						break;
				}
			 }
			if(!overlap)
			{
				fotoxy(mana)
				printf("$");
			}
			}
			이런식? 내가 한거 고쳐야함
			마나 먹고 점수 올리는거 마나는 1개씩만 출력(변수를 1과 0으로 선언해서 생기면 1이고)
	}
*/