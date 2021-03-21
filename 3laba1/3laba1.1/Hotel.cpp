#include "RoomsInHotel.h"
#include"Re�eption.h"
#include"Barman.h"
#include"Concierge.h"
#include<iostream>
#include <new> 
#include<string>
#include <vector>
#include "Hotel.h"
#include <algorithm>
using namespace std;

void Hotel::show()
{
	addConcierge(concierge);
	int i;
	while (1)
	{
		system("CLS");
		cout << "�����: " << hotelname << ", ���������� ����: " << starsnumber << endl;
		cout << "1 - ������� �����" << endl;
		cout << "2 - �������� �����" << endl;
		cout << "3 - �������" << endl;
		cout << "0 - ���������� ������" << endl;
		rewind(stdin);
		cin >> i;
		switch (i)
		{
			case 1:
			{
				RoomsInHotel room;
				CreateRooms(rooms_in_hotel);
				int k, n, m;
				while (1)
				{
					system("CLS");
					cout << endl << "1: �������� ������ �����" << endl
						<< "2: ��������� ��������� �������" << endl
						<< "3: �������� ��������� �������" << endl
						<< "4: ���������� ������� �� ������� ����" << endl
						<< "5: ����������" << endl
						<< "0: �����" << endl;
					cin >> k; cout << endl;
					switch (k)
					{
					case 1:system("CLS"); Show(rooms_in_hotel); system("pause"); break;
					case 2:
						do
						{
							system("CLS");
							rewind(stdin);
							cout << "������� ����� ����� � �������, ������� ������ ��������: ";
							cin >> n; cin >> m;
							n = (n - 1) * 3 + m - 1;
							cin >> rooms_in_hotel[n];
						} while (n<0 || n>rooms_in_hotel.size());
						if (rooms_in_hotel[n].GetAvailability())
							rooms_in_hotel[n].SetNumOfPeople(0);
						Edit(rooms_in_hotel, rooms_in_hotel[n].GetFloorNumber(), rooms_in_hotel[n].GetRoomNumber(),
							rooms_in_hotel[n].GetRoomPrice(), rooms_in_hotel[n].GetAvailability(), rooms_in_hotel[n].GetNumOfPeople());
						cout << " ������� ��������" << endl;
						system("pause");
						break;
					case 3:
						system("CLS");
						rewind(stdin);
						cout << "������� ����� ����� � �������, ������� ������ �������: ";
						cin >> n; cin >> m;
						DeleteRoom(rooms_in_hotel, n, m);
						system("pause");
						break;
					case 4:
						system("CLS");
						cin >> room;
						Add(rooms_in_hotel, room);
						cout << endl << "������� ���������" << endl;
						system("pause");
						break;
					case 5:
						while (1)
						{
							system("CLS");
							rewind(stdin);
							cout << "�������� ��� ����������: 1 - �� ����, 2 - �� ���������� ������� ";
							cin >> k;
							if (k == 1)
							{
								sort(rooms_in_hotel.begin(), rooms_in_hotel.end(), [](RoomsInHotel room1, RoomsInHotel room2)
									{
										return 	room1 > room2;
									}

								);
								break;
							}
							if (k == 2)
							{
								sort(rooms_in_hotel.begin(), rooms_in_hotel.end(), [](RoomsInHotel room1, RoomsInHotel room2)
									{
										return 	room1 < room2;
									}
								);
								break;
							}
							system("pause");
						}
						break;
					case 0: break;
					default: cout << "������� �������� ��������, ���������� �����." << endl; system("pause"); break;
					} break;
				} break;
			}break;
			case 2:
			{
				int k;
				do
				{
					system("CLS");
					cout << "�������� ����������, ������������� ���: " << endl;
					cout << "1 - ������" << endl;
					cout << "2 - ��������" << endl;
					cout << "0 - �����" << endl;
					rewind(stdin);
					cin >> k;
					if (k == 1)
					{
						int m;
						do
						{
							system("CLS");
							cout << "1 - �������� ��������� ����������" << endl;
							cout << "2 - �������� ������ ����������" << endl;
							cout << "3 - �������� ����������" << endl;
							cout << "0 - �����" << endl;
							rewind(stdin);
							cin >> m;
							switch (m)
							{
								case 1:	barman.showBarmanInfo(); system("pause"); break;
								case 2: barman.showFullBarmanInfo(); system("pause"); break;
								case 3: barman.editInfo(); system("pause"); break;
							}
						} while (m);
					}
					else if (k == 2)
					{
						int m, a;
						do
						{
							system("CLS");
							cout << "1 - �������� ��������� ����������" << endl;
							cout << "2 - �������� ������ ����������" << endl;
							cout << "3 - �������� ���������� � ��������� ���������" << endl;
							cout << "4 - ������� ���������" << endl;
							cout << "5 - ������ ���������" << endl;
							cout << "0 - �����" << endl;
							rewind(stdin);
							cin >> m;
							switch (m)
							{
							case 1:for (a = 0; a < concierge.size(); a++) {
								cout << a + 1 << ": ";
								concierge[a].showConciergesInfo();
							} system("pause"); break;
							case 2:for (a = 0; a < concierge.size(); a++){
								cout << a + 1 << ": ";
								concierge[a].showFullConciergesInfo();
							}
							system("pause"); break;
							case 3:
								int n;
								cout << "�������� ���������, ��� ���������� �� ������ ��������: ";
								cin >> n;
								concierge[n - 1].editInfo();
								break;
							case 4:
								fireConcierge(concierge);
								break;
							case 5:
								hireConcierge(concierge);
								break;
							}
						} while (m);
					}
				} while (k);
				break;
			}
			case 3:
			{
				rewind(stdin);
				system("CLS");
				cout << "����� �������� ���: " << MTS << endl;
				cout << "����� �������� Velcom: " << Velcom << endl;
				cout << workmode << endl;
				system("pause");
				break;
			}
			case 0: Delete(rooms_in_hotel); return;
		}
	}
}