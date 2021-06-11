#if 1

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    struct POS {
        float x, y, z;
    };
    const int num = 1000;
    struct POS p[num];
    for (int i = 0; i < num; i++) {
        p[i].x = random(-1.0f, 1.0f);
        p[i].y = random(-0.5f, 0.5f);
        p[i].z = random(0.0f, 1.0f);

    }
    while (notQuit) {
        for (int i = 0; i < num; i++) {
            p[i].z -= 0.008f;
            if (p[i].z < 0.0f) {
                p[i].z = 1.0f; 
            }
        }
        fill(0, 0, 0, 60);
        strokeWeight(0);  //clear�łȂ�rect�ō������邱�ƂŋO�Ղ��c��
        rect(0, 0, width, height);
        mathAxis(1.0f);
        stroke(200, 255, 255);
        for (int i = 0; i < num; i++) {
            float size = (1.0f - p[i].z) * 20.0f;
            strokeWeight(size);
            mathPoint(p[i].x/p[i].z, p[i].y/p[i].z); //z�Ŋ��邱�ƂŋO����ς���
        }
    }
}

#else

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //�摜�ǂݍ���
    int unkoImg = loadImage("assets\\unko.png");
    int ufoImg = loadImage("assets\\ufo.png");
    //�ʒu�f�[�^��num�p�ӂ���
    struct POS {
        float x, y, z;
    };
    const int num = 300;
    struct POS p[num];
    //���������_���ɔz�u����
    for (int i = 0; i < num; i++) {
        p[i].x = random(-0.7f, 0.7f);
        p[i].y = random(-0.5f, 0.5f);
        p[i].z = random(0.1f, 1.0f);
    }
    //�|�C���gor�摜�̕\���p�X�C�b�`
    int sw = 0;
    //�J�[�\����\��
    ShowCursor(FALSE);
    //���C�����[�v
    while (notQuit) {
        //�������̍��œh��Ԃ����O�Ղ�`��
        strokeWeight(0);
        fill(0, 0, 0, 90);
        rectMode(CORNER);
        rect(0, 0, width, height);
        //��O�Ɉړ���A�|�C���gor�摜��`��
        axisMode(NODRAW);
        mathAxis(1.0f);
        if (isTrigger(KEY_Z))++sw %= 3;
        rectMode(CENTER);
        stroke(200, 255, 200);
        for (int i = 0; i < num; i++) {
            //�������O�Ɉړ�
            p[i].z += -0.008f;
            float x = p[i].x / p[i].z;
            float y = p[i].y / p[i].z;
            //�E�B���h�E����o���牜�ɒa��������
            if (p[i].z <= 0.0f ||
                x > 1.0f || x < -1.0f ||
                y > 0.56f || y < -0.56f
                ) {
                x = p[i].x = random(-0.7f, 0.7f);
                y = p[i].y = random(-0.5f, 0.5f);
                p[i].z = 1.0f;
            }
            //�_or�摜�̕`��
            float size = 1.0f - p[i].z;
            if (sw == 0) {
                strokeWeight(size * 20);
                mathPoint(x, y);
            }
            else if (sw == 1) {
                mathImage(ufoImg, x, y, 0, size);
            }
            else if (sw == 2) {
                mathImage(unkoImg, x, y, 0, size);
            }
        }
    }
    //�J�[�\���\��
    ShowCursor(TRUE);
}

#endif