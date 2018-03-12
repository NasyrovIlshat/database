#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;
struct VUZ
{
    int uID;
      string uNazvanie,
           uAdres,
           uForma,
           uKolvo,
        uSpec;

    VUZ* uNext;
};
class DB
{
    private:
        string uPathToDB;
        string uEXT;

        VUZ* uFirst;
        VUZ* uRear;
    public:
        DB(string uPath, string uExpanding)
        {
            uPathToDB = uPath;
            uEXT      = uExpanding;
        }

        ~DB()
        {
            clearStructureVUZ();
        }

        string getPathToDB(string uName)
        {
            return uPathToDB + uName + uEXT;
        }
        void addRecordDB(string uName)
        {
            ofstream uFout(getPathToDB(uName).c_str(), ios_base::app);
if ( ! uFout.is_open())
            {
                cout << "�� ������� ������� ��!" << endl;

                return;
            }
do
            {
                uFout << getInput("������� ��������");
                uFout <<  " " + getInput("������� �����");
                uFout <<  " " + getInput("������� ����� ��������");
                uFout << " " + getInput("������� ���-�� ���������");
                uFout << " " + getInput("������� �������������") << endl;
            }
            while (getInput("������ �������� ��� ���� ������? 1 - ��, 0 - ���") != "0");
cout << "�������! �� ������� ��������� ��." << endl;
uFout.close();
        }
void deleteRecordDB(string uName, int uLine)
        {
            int uI = 0;
            string uS_1,
                   uS_2;
            ifstream uFout_1;
            ofstream uFout_2;

            uFout_1.open(getPathToDB(uName).c_str());

            if ( ! uFout_1.is_open())
            {
                cout << "�� ������� ������� ��!" << endl;

                return;
            }
while (getline(uFout_1, uS_1))
            {
                if (uI++ != uLine)
                {
                    uS_2 += uS_1 + "\n";
                }
            }
uFout_1.close();
            uFout_2.open(getPathToDB(uName).c_str());
            uFout_2 << uS_2.erase(uS_2.find_last_not_of(" \n\r\t") + 1);
            uFout_2.close();
cout << "�������! �� ������� ������� ������." << endl;
        }
void editRecordDB(string uName, int uLine)
        {
            int uI = 0;
            string uS_1,
                   uS_2;
            ifstream uFout_1;
            ofstream uFout_2;
uFout_1.open(getPathToDB(uName).c_str());
if ( ! uFout_1.is_open())
            {
                cout << "�� ������� ������� ��!" << endl;

                return;
            }
while (getline(uFout_1, uS_1))
            {
                if (uI++ != uLine)
                {
                    uS_2 += uS_1 + "\n";
                }
                else
                {
                    uS_2 += getInput("������� ��������");
                    uS_2 += " " + getInput("������� �����");
                    uS_2 += " " + getInput("������� ����� ��������");
                    uS_2 += " " + getInput("������� ���-�� ���������");
                    uS_2 += " " + getInput("������� �������������") + "\n";
                }
            }
uFout_1.close();
uFout_2.open(getPathToDB(uName).c_str());
            uFout_2 << uS_2.erase(uS_2.find_last_not_of(" \n\r\t") + 1);
            uFout_2.close();
cout << "�������! �� ������� ��������������� ������." << endl;
        }
void sortRecordDB(string uName, int uType_1, int uType_2)
        {
            fillingStructureVUZ(uName);
VUZ *uVUZ_1,
                  *uVUZ_2;

            bool uCheck;

            for(uVUZ_1 = uFirst; uVUZ_1; uVUZ_1 = uVUZ_1->uNext)
            {
                for(uVUZ_2 = uFirst; uVUZ_2; uVUZ_2 = uVUZ_2->uNext)
                {
                    uCheck = false;

                    if (uType_1 == 1)
                    {
                        if (uType_2 == 1)
                        {
                            uCheck = uVUZ_1->uID > uVUZ_2->uID;
                        }
                        else if (uType_2 == 2)
                        {
                            uCheck = uVUZ_1->uNazvanie > uVUZ_2->uNazvanie;
                        }
                        else if (uType_2 == 3)
                        {
                            uCheck = uVUZ_1->uAdres > uVUZ_2->uAdres;
                        }
                        else if (uType_2 == 4)
                        {
                            uCheck = uVUZ_1->uForma > uVUZ_2->uForma;
                        }
                        else if (uType_2 == 5)
                        {
                            uCheck = uVUZ_1->uKolvo > uVUZ_2->uKolvo;
                        }
                        else if (uType_2 == 6)
                        {
                            uCheck = uVUZ_1->uSpec > uVUZ_2->uSpec;
                        }
                    }
                    else if (uType_1 == 2)
                    {
                        if (uType_2 == 1)
                           {
                            uCheck = uVUZ_1->uID < uVUZ_2->uID;
                        }
                        else if (uType_2 == 2)
                        {
                            uCheck = uVUZ_1->uNazvanie < uVUZ_2->uNazvanie;
                        }
                        else if (uType_2 == 3)
                        {
                            uCheck = uVUZ_1->uAdres < uVUZ_2->uAdres;
                        }
                        else if (uType_2 == 4)
                        {
                            uCheck = uVUZ_1->uForma < uVUZ_2->uForma;
                        }
                        else if (uType_2 == 5)
                        {
                            uCheck = uVUZ_1->uKolvo < uVUZ_2->uKolvo;
                        }
                        else if (uType_2 == 6)
                        {
                            uCheck = uVUZ_1->uSpec < uVUZ_2->uSpec;
                        }
                    }

                    if(uCheck)
                    {
                        int uID = uVUZ_1->uID;
                            

                        string uNazvanie = uVUZ_1->uNazvanie,
                               uAdres = uVUZ_1->uAdres,
                               uForma = uVUZ_1->uForma,
                               uKolvo = uVUZ_1->uKolvo,
                            uSpec = uVUZ_1->uSpec;

                        uVUZ_1->uID = uVUZ_2->uID;
                        uVUZ_1->uNazvanie = uVUZ_2->uNazvanie;
                        uVUZ_1->uAdres = uVUZ_2->uAdres;
                        uVUZ_1->uForma = uVUZ_2->uForma;
                        uVUZ_1->uKolvo = uVUZ_2->uKolvo;
                        uVUZ_1->uSpec = uVUZ_2->uSpec;
                        uVUZ_2->uID = uID;
                        uVUZ_2->uNazvanie = uNazvanie;
                        uVUZ_2->uAdres = uAdres;
                        uVUZ_2->uForma = uForma;
                        uVUZ_2->uKolvo = uKolvo;
                        uVUZ_2->uSpec = uSpec;
                    }
                }
            }

            printStructureVUZ(uName);

           
        }

        void saveDumpStructureVUZ(string uName, string uPrefix)
        {
            ofstream uFout(getPathToDB(uPrefix + "_" + uName).c_str(), ios_base::app);

            if ( ! uFout.is_open())
            {
                cout << "�� ������� ������� ��!" << endl;

                return;
            }

            VUZ *uTemp = uFirst;

            while(uTemp)
            {
                uFout
                    << uTemp->uNazvanie
                    << " "
                    << uTemp->uAdres
                    << " "
                    << uTemp->uForma
                    << " "
                    << uTemp->uKolvo
                    << " "
                    << uTemp->uSpec
                    << endl;

                uTemp = uTemp->uNext;
            }

            cout << "�������! �� ������� ������� ��������������� ��." << endl;

            uFout.close();
        }

        void searchRecordDB(string uName)
        {
            string uSearch_1,
            	   uSearch_2,
            	   uSearch_3,
            	   uSearch_4 = "0",
                   uGolf;

			uSearch_1 = getInput("������� ��������");
			uSearch_2 = getInput("������� ����� ��������");
			uSearch_3 = getInput("������� �������������");

            fillingStructureVUZ(uName);

            VUZ *uTemp = uFirst;

            bool uCheck;
            bool uCheck_2;
            bool uCheck_3;
            bool uCheck_4;

            char *uPch;

            while(uTemp)
            {
                uCheck_2 = uSearch_1 != "" && ((strstr(uTemp->uNazvanie.c_str(), uSearch_1.c_str()) != NULL) || strstr(uSearch_4.c_str(), uSearch_1.c_str()));
				uCheck_3 = uSearch_2 != "" && ((strstr(uTemp->uForma.c_str(), uSearch_2.c_str()) != NULL) || strstr(uSearch_4.c_str(), uSearch_2.c_str()));
                uCheck_4 = uSearch_3 != "" && ((strstr(uTemp->uSpec.c_str(), uSearch_3.c_str()) != NULL) || strstr(uSearch_4.c_str(), uSearch_3.c_str()));

                if ( ! uCheck && uCheck_2 && uCheck_3 && uCheck_4)
                {
                    uCheck = true;
                    printStructureVUZLabel();
            	}
            	
            	if (uCheck_2 && uCheck_3 && uCheck_4)
            	{
            		 printRecordVUZ(uTemp);
            	}
            	
                uTemp = uTemp->uNext;
            }

            if ( ! uCheck)
            {
                cout << "�� ������� �� ������� �� ����� ������" << endl;
            }
        }

        void fillingStructureVUZ(string uName)
        {
            clearStructureVUZ();

            ifstream uFout;

            uFout.open(getPathToDB(uName).c_str());

            if ( ! uFout.is_open())
            {
                cout << "�� ������� ������� ��!" << endl;

                return;
            }

            int uCountOfRecords = getCountOfRecords(uFout);

            if ( ! uCountOfRecords)
            {
                cout << "������ � �� �����������!" << endl;

                return;
            }

            // ���������� �����, �� ������ �����
            uFout.clear();
            uFout.seekg(0, ios_base::beg);

            for (int uI = 0; uI < uCountOfRecords; uI++)
            {
                VUZ *uNewVUZ = new VUZ;

                uNewVUZ->uID = uI + 1;

                uFout
                    >> uNewVUZ->uNazvanie
                    >> uNewVUZ->uAdres
                    >> uNewVUZ->uForma
                    >> uNewVUZ->uKolvo
                    >> uNewVUZ->uSpec;

                uNewVUZ->uNext = NULL;

                if (uFirst == NULL)
                {
                    uFirst = uNewVUZ;
                }
                else
                {
                    uRear->uNext = uNewVUZ;
                }

                uRear = uNewVUZ;
            }

            uFout.close();
        }

        void printStructureVUZ(string uName)
        {
            VUZ *uTemp = uFirst;

            printStructureVUZLabel();

            while(uTemp)
            {
                printRecordVUZ(uTemp);
                uTemp = uTemp->uNext;
            }
        }

        void printStructureVUZLabel()
        {
            cout
                << left
                << setw(4)
                << "ID"
                << setw(9)
                << "��������"
                << setw(23)
                << "�����"
                << setw(15)
                << "����� ��������"
                << setw(10)
                << "���-��"
                << setw(10)
                << "������������"
                << endl;
        }

        void printRecordVUZ(VUZ *uTemp)
        {
            cout
                << setw(4)
                << uTemp->uID
                << setw(9)
                << uTemp->uNazvanie
                << setw(23)
                << uTemp->uAdres
                << setw(15)
                << uTemp->uForma
                << setw(10)
                << uTemp->uKolvo
                << setw(10)
                << uTemp->uSpec
                << endl;
        }

        int getCountOfRecords(ifstream &uFout)
        {
            int uNumberOfLines = 0;
            string uS;

            while (getline(uFout, uS))
            {
                ++uNumberOfLines;
            }

            return uNumberOfLines;
        }

        void deleteDB(string uName)
        {
            remove(getPathToDB(uName).c_str());

            cout << "�������! �� ������� ������� ��." << endl;
        }

        void clearStructureVUZ()
        {
            uFirst = NULL;
            uRear  = NULL;
        }

        string getInput(string uMessage)
        {
            string uInput;

            cout << uMessage + ": ";
            cin >> uInput;

            return uInput;
        }
};

int main()
{
    setlocale(LC_ALL, "rus");

    DB DB("C:\\Base\\", ".txt");

    int ID;

    while(true)
    {
        cout
            << endl
            << "1. ����� � ��"
            << endl
            << endl
            << "��� ����� (1-4): ";
            keybd_event ('4',0,0,0);
             keybd_event ('4',0,KEYEVENTF_KEYUP,0);
             keybd_event (VK_RETURN,MapVirtualKeyA(VK_RETURN,0),0,0);
             keybd_event (VK_RETURN,MapVirtualKeyA(VK_RETURN,0),KEYEVENTF_KEYUP,0);

        cin >> ID;

        cout << endl;

        system("cls");

        switch(ID)
        {
                      case 4:
            {
                bool uCheck = false;

                string uName = DB.getInput("������� ��� ��");

                while(true)
                {
                    if (uCheck)
                    {
                        break;
                    }

                    cout
                        << endl
                        << "����:"
                        << endl
                        << endl
                        << "1. ������� ������"
                        << endl
                        << "2. �������� ������"
                        << endl
                        << "3. ������� ������"
                        << endl
                        << "4. ����� �������"
                        << endl
                        << "5. ���������� �������"
                        << endl
                        << "6. �������������� ������"
                        << endl
                        << "7. ����� �� ���������"
                        << endl
                        << endl
                        << "��� ����� (1-7): ";

                    cin >> ID;

                    cout << endl;

                    system("cls");

                    switch(ID)
                    {
                        case 1:
                        {
                            DB.fillingStructureVUZ(uName);
                            DB.printStructureVUZ(uName);
                            break;
                        }

                        case 2:
                        {
                            DB.addRecordDB(uName);
                            break;
                        }

                        case 3:
                        {
                            DB.deleteRecordDB(uName, atoi(DB.getInput("������� ID ������").c_str()) - 1);
                            break;
                        }

                        case 4:
                        {
                            DB.searchRecordDB(uName);
                            break;
                        }

                        case 5:
                        {
                            DB.sortRecordDB(
                                uName,
                                atoi(DB.getInput("������� ��� ����������. 1 - ����. 2 - ����.").c_str()),
                                atoi(DB.getInput("������� ����. 1 - ID. 2 - ��������. 3 - �����. 4 - ����� ��������.  5 - ���-�� ���������. 6 - �������������.").c_str())
                            );

                            break;
                        }

                        case 6:
                        {
                            DB.editRecordDB(uName, atoi(DB.getInput("������� ID ������").c_str()) - 1);
                            break;
                        }

                        case 7:
                        {
                            exit(0);
                            break;
                        }

                        default:
                        {
                            cout << "������ � ������ ������ ����. ���������!" << endl;
                            break;
                        }
                    }
                }

                break;
            }

            default:
            {
                cout << "������ � ������ ������ ����. ���������!" << endl;
                break;
            }
        }
    }

    return 0;
}
