#include "TXLib.h"

struct Form
{
    string question;
    HDC pic1;
    string answer1;
    HDC pic2;
    string answer2;
    HDC pic3;
    string answer3;
};

bool Click(int x)
{
    return (txMouseButtons() == 1 && txMouseX()>x && txMouseX()<x+240 && txMouseY()>450 && txMouseY()<480);
}

int main()
{
txCreateWindow (800, 600);

    int n_question = 1;
    char stroka[50];

    Form form;

    Form form_list[10];
    form_list[0] = {"В каком городе больше население?", txLoadImage("Pictures/ulyanovsk.bmp"), "Ульяновск", txLoadImage("Pictures/samara.bmp"), "Самара", txLoadImage("Pictures/moscow.bmp"), "Москва"};
    form_list[1] = {"Каком город находится севернее остальных?", txLoadImage("Pictures/moscow.bmp"), "Москва", txLoadImage("Pictures/ulyanovsk.bmp"), "Ульяновск", txLoadImage("Pictures/samara.bmp"), "Самара"};
    form_list[2] = {"В каком городе России метро начало работать в 1935 году?", txLoadImage("Pictures/moscow.bmp"), "Москва", txLoadImage("Pictures/piter.bmp"), "Санкт-Петербург", txLoadImage("Pictures/eburg.bmp"), "Екатеринбург"};

    while(n_question<=3)
    {
        form = form_list[n_question-1];

        txSetFillColor (TX_BLACK);
        txClear();
        txBegin();
        //ШАБЛОН
        txSetColor (TX_BLACK);
        txSetFillColor (TX_TRANSPARENT);
        //Внешняя рамка
        txRectangle (10, 10, 790, 590);
        txSelectFont("Times New Roman", 25);

        txSetFillColor (TX_WHITE);
        //Область номера вопроса
        txRectangle (600, 20, 750, 50);
        sprintf(stroka, "Вопрос № %d", n_question);
        txDrawText(600, 20, 750, 50, stroka);
        //Область текста вопроса
        txRectangle (100, 100, 700, 130);
        txDrawText(100, 100, 700, 130, form.question.c_str());

        //Область картинки первого ответа
        txRectangle (30, 200, 270, 400);
        txBitBlt(txDC(), 30, 225, 240, 150, form.pic1);
        //Область картинки второго ответа
        txRectangle (280, 200, 520, 400);
        txBitBlt(txDC(), 280, 225, 240, 150, form.pic2);
        //Область картинки третьего ответа
        txRectangle (530, 200, 770, 400);
        txBitBlt(txDC(), 530, 225, 240, 150, form.pic3);

        //Область текста первого ответа
        txRectangle (30, 450, 270, 480);
        txDrawText(30, 450, 270, 480, form.answer1.c_str());
        //Область текста второго ответа
        txRectangle (280, 450, 520, 480);
        txDrawText(280, 450, 520, 480, form.answer2.c_str());
        //Область текста третьего ответа
        txRectangle (530, 450, 770, 480);
        txDrawText(530, 450, 770, 480, form.answer3.c_str());

        if(Click(30))
        {
            while (txMouseButtons() == 1)
            {
                txSleep(10);
            }
            n_question ++;
        }

        if(Click(280))
        {
            while (txMouseButtons() == 1)
            {
                txSleep(10);
            }
            n_question ++;
        }

        if(Click(530))
        {
            while (txMouseButtons() == 1)
            {
                txSleep(10);
            }
            n_question ++;
        }

        txEnd();

    }
    txSetFillColor (TX_BLACK);
    txClear();

    txDeleteDC(form.pic1);
    txDeleteDC(form.pic2);
    txDeleteDC(form.pic3);

txTextCursor (false);
return 0;
}

