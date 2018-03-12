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
                cout << "Не удалось открыть БД!" << endl;

                return;
            }
do
            {
                uFout << getInput("Введите название");
                uFout <<  " " + getInput("Введите адрес");
                uFout <<  " " + getInput("Введите форму обучения");
                uFout << " " + getInput("Введите кол-во студентов");
                uFout << " " + getInput("Введите специальность") << endl;
            }
            while (getInput("Хотите добавить еще одну запись? 1 - Да, 0 - Нет") != "0");
cout << "Отлично! Вы успешно заполнили БД." << endl;
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
                cout << "Не удалось открыть БД!" << endl;

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
cout << "Отлично! Вы успешно удалили запись." << endl;
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
                cout << "Не удалось открыть БД!" << endl;

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
                    uS_2 += getInput("Введите название");
                    uS_2 += " " + getInput("Введите адрес");
                    uS_2 += " " + getInput("Введите форму обучения");
                    uS_2 += " " + getInput("Введите кол-во студентов");
                    uS_2 += " " + getInput("Введите специальность") + "\n";
                }
            }
uFout_1.close();
uFout_2.open(getPathToDB(uName).c_str());
            uFout_2 << uS_2.erase(uS_2.find_last_not_of(" \n\r\t") + 1);
            uFout_2.close();
cout << "Отлично! Вы успешно отредактировали запись." << endl;
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
                cout << "Не удалось открыть БД!" << endl;

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

            cout << "Отлично! Вы успешно создали отсортированную БД." << endl;

            uFout.close();
        }

        void searchRecordDB(string uName)
        {
            string uSearch_1,
            	   uSearch_2,
            	   uSearch_3,
            	   uSearch_4 = "0",
                   uGolf;

			uSearch_1 = getInput("Введите название");
			uSearch_2 = getInput("Введите форму обучения");
			uSearch_3 = getInput("Введите специальность");

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
                cout << "По запросу не найдено ни одной записи" << endl;
            }
        }

        void fillingStructureVUZ(string uName)
        {
            clearStructureVUZ();

            ifstream uFout;

            uFout.open(getPathToDB(uName).c_str());

            if ( ! uFout.is_open())
            {
                cout << "Не удалось открыть БД!" << endl;

                return;
            }

            int uCountOfRecords = getCountOfRecords(uFout);

            if ( ! uCountOfRecords)
            {
                cout << "Записи в БД отсутствуют!" << endl;

                return;
            }

            // Сбрасываем поток, до начала файла
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
                << "Название"
                << setw(23)
                << "Адрес"
                << setw(15)
                << "Форма обучения"
                << setw(10)
                << "Кол-во"
                << setw(10)
                << "Спецальность"
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

            cout << "Отлично! Вы успешно удалили БД." << endl;
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
            << "1. Войти в БД"
            << endl
            << endl
            << "Ваш выбор (1-4): ";
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

                string uName = DB.getInput("Введите имя БД");

                while(true)
                {
                    if (uCheck)
                    {
                        break;
                    }

                    cout
                        << endl
                        << "Меню:"
                        << endl
                        << endl
                        << "1. Вывести записи"
                        << endl
                        << "2. Добавить запись"
                        << endl
                        << "3. Удалить запись"
                        << endl
                        << "4. Поиск записей"
                        << endl
                        << "5. Сортировка записей"
                        << endl
                        << "6. Редактирование записи"
                        << endl
                        << "7. Выход из программы"
                        << endl
                        << endl
                        << "Ваш выбор (1-7): ";

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
                            DB.deleteRecordDB(uName, atoi(DB.getInput("Введите ID записи").c_str()) - 1);
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
                                atoi(DB.getInput("Введите тип сортировки. 1 - Убыв. 2 - Возр.").c_str()),
                                atoi(DB.getInput("Введите поле. 1 - ID. 2 - Название. 3 - Адрес. 4 - Форма обучения.  5 - Кол-во студентов. 6 - Специальности.").c_str())
                            );

                            break;
                        }

                        case 6:
                        {
                            DB.editRecordDB(uName, atoi(DB.getInput("Введите ID записи").c_str()) - 1);
                            break;
                        }

                        case 7:
                        {
                            exit(0);
                            break;
                        }

                        default:
                        {
                            cout << "Ошибка в выборе пункта меню. Повторите!" << endl;
                            break;
                        }
                    }
                }

                break;
            }

            default:
            {
                cout << "Ошибка в выборе пункта меню. Повторите!" << endl;
                break;
            }
        }
    }

    return 0;
}
