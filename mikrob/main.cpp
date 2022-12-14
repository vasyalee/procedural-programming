#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, g;
    ifstream dat;
    ofstream out;
    double now[21][21];
    double then[21][21];
    char test;
    cout << "Enter the number of generations: ";
    cin >> n;
    dat.open("DATA.txt");
    g = 0;
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            dat.get(test);
            if (test == 'M')
            {
                now[i][j] = 1;
            }
            else
            {
                now[i][j] = 0;
            }
        }

    }
    cout << "---------------------------------------------------" << endl;
    out.open("OUT.txt");
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            out << now[i][j];
        }
    }
    dat.close();
    for (int q = 0; q < n; q++) {
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                if (now[i][j] == 0) {
                    then[i][j] = now[i][j] + 1;
                } else if (now[i][j] == 12) {
                    then[i][j] = 0;
                } else {
                    if (i == 0) {
                        if (j == 0) {
                            if ((now[i][j + 1] != 0) and (now[i + 1][j] != 0)) {
                                then[i][j] = now[i][j] + 1;
                            } else {
                                then[i][j] = 0;
                            }
                        } else if (j == 20) {
                            if ((now[i][j - 1] != 0) and (now[i + 1][j] != 0)) {
                                then[i][j] = now[i][j] + 1;
                            } else {
                                then[i][j] = 0;
                            }
                        } else {
                            if (((now[i][j - 1] != 0) and (now[i][j + 1] != 0)) or
                                ((now[i][j - 1] != 0) and (now[i + 1][j] != 0)) or ((now[i][j + 1] != 0)) and
                                ((now[i + 1][j] != 0))) {
                                then[i][j] = now[i][j] + 1;
                            } else {
                                then[i][j] = 0;
                            }
                        }
                    } else if (i == 20) {
                        if (j == 0) {
                            if ((now[i][j] != 0) and (now[i - 1][j] != 0)) {
                                then[i][j] = now[i][j] + 1;
                            } else {
                                then[i][j] = 0;
                            }
                        } else if (j == 20) {
                            if ((now[i][j - 1] != 0) and (now[i - 1][j] != 0)) {
                                then[i][j] = now[i][j] + 1;
                            } else {
                                then[i][j] = 0;
                            }
                        } else {
                            if (((now[i][j - 1] != 0) and (now[i][j + 1] != 0)) or
                                ((now[i][j - 1] != 0) and (now[i - 1][j] != 0)) or
                                ((now[i][j + 1] != 0) and (now[i - 1][j] != 0))) {
                                then[i][j] = now[i][j] + 1;
                            } else {
                                then[i][j] = 0;
                            }
                        }
                    } else if (j == 0) {
                        if (((now[i][j + 1] != 0) and (now[i - 1][j] != 0)) or
                            ((now[i][j + 1] != 0) and (now[i + 1][j] != 0)) or
                            ((now[i - 1][j] != 0) and (now[i + 1][j] != 0))) {
                            then[i][j] = now[i][j] + 1;
                        } else {
                            then[i][j] = 0;
                        }
                    } else if (j == 20) {
                        if (((now[i][j - 1] != 0) and (now[i - 1][j] != 0)) or
                            ((now[i][j - 1] != 0) and (now[i + 1][j] != 0)) or
                            ((now[i - 1][j] != 0) and (now[i + 1][j] != 0))) {
                            then[i][j] = now[i][j] + 1;
                        } else {
                            then[i][j] = 0;
                        }
                    } else {
                        if (((now[i][j - 1] != 0) and (now[i - 1][j] != 0)) or
                            ((now[i][j - 1] != 0) and (now[i + 1][j] != 0)) or
                            ((now[i][j - 1] != 0) and (now[i][j + 1] != 0)) or
                            ((now[i + 1][j] != 0) and (now[i - 1][j] != 0)) or
                            ((now[i][j + 1] != 0) and (now[i - 1][j] != 0)) or
                            ((now[i][j + 1] != 0) and (now[i + 1][j] != 0))) {
                            then[i][j] = now[i][j] + 1;
                        } else {
                            then[i][j] = 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                now[i][j] = then[i][j];
            }
        }

        for (int i = 0; i < 21; i++)
        {
            for (int j = 0; j < 21; j++) {
                cout << then[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----------------------------------------------------------------" << endl;
    }
}