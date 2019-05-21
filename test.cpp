//
// Created by admin on 19.05.2019.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "protPredp.h"

using testing::Eq;
namespace {
    class ClassDeclaration:public testing::Test{
    public:
        GR sewerage;
        ClassDeclaration(){
            sewerage;
        }
    };
}

TEST_F(ClassDeclaration, nameOfTheTest1){
    char str1[]="S O 3";
    char str2[]="S P 3";
    char str3[]="O Q 3";
    char str4[]="O P 2";
    char str5[]="P R 2";
    char str6[]="Q R 4";
    char str7[]="Q T 2";
    char str8[]="R T 3";
    bool error=false;
    if (!error) error=sewerage.parser(str1);
    if (!error) error=sewerage.parser(str2);
    if (!error) error=sewerage.parser(str3);
    if (!error) error=sewerage.parser(str4);
    if (!error) error=sewerage.parser(str5);
    if (!error) error=sewerage.parser(str6);
    if (!error) error=sewerage.parser(str7);
    if (!error) error=sewerage.parser(str8);
    if (!error)
    {
        if (sewerage.checkST())
        {
            sewerage.changeMatrix();
            sewerage.madeMatrices();
            if (sewerage.MaxWay()==5)
                SUCCEED();
            else
                FAIL();
        }
        else
            FAIL();
    }
    else
        FAIL();
}

TEST_F(ClassDeclaration, nameOfTheTest2){
    char str1[]="S B 3";
    char str2[]="B T 3";
    char str3[]="A A 11";

    bool error=false;
    if (!error) error=sewerage.parser(str1);
    if (!error) error=sewerage.parser(str2);
    if (!error) error=sewerage.parser(str3);
    if (!error)
    {
        if (sewerage.checkST())
        {
            sewerage.changeMatrix();
            sewerage.madeMatrices();
            if (sewerage.MaxWay()==3)
                SUCCEED();
            else
                FAIL();
        }
        else
            FAIL();
    }
    else
        FAIL();
}
TEST_F(ClassDeclaration, nameOfTheTest3){
    char str1[]="T T 3";
    char str2[]="S A 3";
    char str3[]="A B 5";
    char str4[]="B S 7";
    sewerage.parser(str1);
    sewerage.parser(str2);
    sewerage.parser(str3);
    sewerage.parser(str4);
    sewerage.changeMatrix();
    sewerage.madeMatrices();
    if (sewerage.MaxWay()==0)
        SUCCEED();
    else
        FAIL();
}
TEST_F(ClassDeclaration, nameOfTheTest4){
    char str1[]="S S 3";
    char str2[]="T A 3";
    char str3[]="A B 5";
    char str4[]="B T 7";
    sewerage.parser(str1);
    sewerage.parser(str2);
    sewerage.parser(str3);
    sewerage.parser(str4);
    sewerage.changeMatrix();
    sewerage.madeMatrices();
    if (sewerage.MaxWay()==0)
        SUCCEED();
    else
        FAIL();
}

TEST_F(ClassDeclaration, nameOfTheTest5){
    char str1[]="S S 3";
    char str2[]="A S 3";
    char str3[]="B S 3";
    char str4[]="B T 2";
    char str5[]="B A 2";

    bool error=false;
    if (!error) error=sewerage.parser(str1);
    if (!error) error=sewerage.parser(str2);
    if (!error) error=sewerage.parser(str3);
    if (!error) error=sewerage.parser(str4);
    if (!error) error=sewerage.parser(str5);
    if (!error)
    {
        if (sewerage.checkST())
        {
            sewerage.changeMatrix();
            sewerage.madeMatrices();
            if (sewerage.MaxWay()==0)
                SUCCEED();
            else
                FAIL();
        }
        else
            FAIL();
    }
    else
        FAIL();
}

TEST_F(ClassDeclaration, nameOfTheTest6){
    char str1[]="";

    bool error=false;
    if (!error) error=sewerage.parser(str1);

    if (!error)
        FAIL();
    else
        SUCCEED();
}

TEST_F(ClassDeclaration, nameOfTheTest7){
    char str1[]="T A 3";
    char str2[]="A B 3";
    char str3[]="T B 3";
    bool error=false;
    if (!error) error=sewerage.parser(str1);
    if (!error) error=sewerage.parser(str2);
    if (!error) error=sewerage.parser(str3);

    if (!error)
    {
        if (sewerage.checkST())
            FAIL();
        else
            SUCCEED();
    }
    else
        FAIL();
}
TEST_F(ClassDeclaration, nameOfTheTest8){
    char str1[]="S T 1";
    char str2[]="abrakadabra";

    bool error=false;
    if (!error) error=sewerage.parser(str1);
    if (!error) error=sewerage.parser(str2);

    if (!error)
        FAIL();
    else
        SUCCEED();
}
TEST_F(ClassDeclaration, nameOfTheTest9){
    char str1[]="ABRA BRA 3";
    char str2[]="BRA T 3";
    char str3[]="S ABRA 343";
    bool error=false;
    if (!error) error=sewerage.parser(str1);
    if (!error) error=sewerage.parser(str2);
    if (!error) error=sewerage.parser(str3);
    if (!error)
    {
        if (sewerage.checkST())
        {
            sewerage.changeMatrix();
            sewerage.madeMatrices();
            if (sewerage.MaxWay()==3)
                SUCCEED();
            else
                FAIL();
        }
        else
            FAIL();
    }
    else
        FAIL();
}
TEST_F(ClassDeclaration, nameOfTheTest10){
    char str1[]="S T 1";
    char str2[]="T S 2";
    bool error=false;
    if (!error) error=sewerage.parser(str1);
    if (!error) error=sewerage.parser(str2);
    if (!error)
    {
        if (sewerage.checkST())
        {
            sewerage.changeMatrix();
            sewerage.madeMatrices();
            if (sewerage.MaxWay()==1)
                SUCCEED();
            else
                FAIL();
        }
        else
            FAIL();
    }
    else
        FAIL();
}
TEST_F(ClassDeclaration, nameOfTheTest11){
    char str1[]="S T -1";

    bool error=false;
    if (!error) error=sewerage.parser(str1);

    if (!error)
        FAIL();
    else
        SUCCEED();
}

TEST_F(ClassDeclaration, nameOfTheTest12){
    char str1[]="T S 3";

    bool error=false;
    if (!error) error=sewerage.parser(str1);

    if (!error)
    {
        if (sewerage.checkST())
        {
            sewerage.changeMatrix();
            sewerage.madeMatrices();
            if (sewerage.MaxWay()==0)
                SUCCEED();
            else
                FAIL();
        }
        else
            FAIL();
    }
    else
        FAIL();
}
