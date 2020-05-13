/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   testproject = main.cpp
//
//   
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"		//Dxlib���C�u�������g�p����
#include "main.h"

//�萔
//----------------------------------
#define SCREEN_SIZE_X 600
#define SCREEN_SIZE_Y 500

//�ϐ�
//----------------------------------
int gameCounter;
int haikeiImage;

int playerImage;				//���@�̉摜ID
int playerPosX;					//���@��X���W
int playerPosY;					//���@��Y���W

int enemyImage;

//�\���̒�`
struct FILE_DATA {
	int data1;
	int hiscore;
};

//�t�@�C������`
char filename[] = "data.dat";
struct FILE_DATA fileData;



//�t�@�C������֐�
//bool SaveData(void);
//bool LoadData(void);

// ========= WinMain�֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �V�X�e���̏�����
	if (SystemInit() == false)
	{
		return -1;
	}

	// --------�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//��ʏ���

		GameMain();

		gameCounter++;
		ScreenFlip();		//����ʂ�\��ʂɏu�ԃR�s�[
	}

	DxLib_End();			// DX���C�u�����̏I������
	return 0;				//���̃v���O�����̏I��
}

//---------------------------------------------
// �V�X�e���̏�����
bool SystemInit(void)
{
	// ----------�V�X�e������
	SetWindowText("TestProject");
	//�V�X�e������
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);							//true:window false:�t���X�N���[��
	if (DxLib_Init() == -1)							//DX���C�u��������������
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);					//�ЂƂ܂��o�b�N�o�b�t�@�ɕ`��

	// ------�O���t�B�b�N�̓o�^�@---------

	//�w�i
	haikeiImage = LoadGraph("image/haikei.png");
	//���@
	playerImage = LoadGraph("image/player.png");

	enemyImage = LoadGraph("image/enemy.png");


	// ------�ϐ��������@-----------
	gameCounter = 0;


	//�t�@�C���p�f�[�^������
	///fileData.data1 = 1000;
	//fileData.hiscore = 5000;

	return true;
}

//---------------------------------------------
// �v���C������
void GameMain(void)
{
	GameMainDraw();
}


//---------------------------------------------
// �v���C���̕`��
void GameMainDraw(void)
{


	//�w�i�`��
	DrawGraph(0, 0, haikeiImage, true);

	DrawGraph(0, 450, playerImage, true);

	DrawGraph(150, 450, enemyImage, true);

	DrawFormatString(0, 0, 0xFFFFFF, "GameMain : %d", gameCounter);
}


