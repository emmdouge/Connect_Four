
#include <iostream>
#include <string>

using namespace std;

void display(string **p_p_c4_board, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout<<p_p_c4_board[i][j];
        }
    cout<<endl;
    }

    for (int i = 1; i < size+1; ++i)
    {
        cout<<" "<<i<<" ";
    }

    cout<<endl;

return;
}

void player_1(string **p_p_c4_board, char you, int size)
{
    int drop = -1;
    int stabilizer = 0;

    while(drop == 0 || drop > size || drop < 0 )
    {
        cout<<"Player 1: ";
        cin>>drop;
        cout<<endl;

            if (drop == 0 || drop > size)
            {
                cout<<endl;
                cout<<"Invalid Choice!";
                cout<<endl;
                continue;
            }

            else if (p_p_c4_board[0][drop-1].find("IoI") != string::npos || p_p_c4_board[0][drop-1].find("IxI") != string::npos )
            {
                drop = 0;
                cout<<endl;
                cout<<"You can't put it there!";
                cout<<endl;
                continue;
            }

            else
            {
                if (p_p_c4_board[(size-1)-stabilizer][drop-1].find("I I") != string::npos )
                {
                    p_p_c4_board[(size-1)-stabilizer][drop-1] = "IoI";
                    break;
                }
                else if (p_p_c4_board[(size-1)-stabilizer][drop-1].find("IoI") != string::npos || p_p_c4_board[(size-1)-stabilizer][drop-1].find("IxI") != string::npos)
                {
                    for (;p_p_c4_board[(size-1)-stabilizer][drop-1].find("IoI") != string::npos || p_p_c4_board[(size-1)-stabilizer][drop-1].find("IxI") != string::npos && stabilizer < size; )
                    {
                        ++stabilizer;
                        if (p_p_c4_board[(size-1)-stabilizer][drop-1].find("I I") != string::npos )
                        {
                            p_p_c4_board[(size-1)-stabilizer][drop-1] = "IoI";
                            break;
                        }
                    }

                }

            }



    }
return;
}

//Drop Algorithm
void player_2(string **p_p_c4_board, char him, int size)
{
    int drop = -1;
    int stabilizer = 0;

    while(drop == 0 || drop > size || drop < 0 )
    {
        cout<<"Player 2: ";
        cin>>drop;
        cout<<endl;

            if (drop == 0 || drop > size)
            {
                cout<<endl;
                cout<<"Invalid Choice!";
                cout<<endl;
                continue;
            }

            else if (p_p_c4_board[0][drop-1].find("IoI") != string::npos || p_p_c4_board[0][drop-1].find("IxI") != string::npos )
            {
                drop = 0;
                cout<<endl;
                cout<<"You can't put it there!";
                cout<<endl;
                continue;
            }

            else
            {
                if (p_p_c4_board[(size-1)-stabilizer][drop-1].find("I I") != string::npos )
                {
                    p_p_c4_board[(size-1)-stabilizer][drop-1] = "IxI";
                    break;
                }
                else if (p_p_c4_board[(size-1)-stabilizer][drop-1].find("IoI") != string::npos || p_p_c4_board[(size-1)-stabilizer][drop-1].find("IxI") != string::npos)
                {
                    for (;p_p_c4_board[(size-1)-stabilizer][drop-1].find("IoI") != string::npos || p_p_c4_board[(size-1)-stabilizer][drop-1].find("IxI") != string::npos && stabilizer < size; )
                    {
                        ++stabilizer;
                        if (p_p_c4_board[(size-1)-stabilizer][drop-1].find("I I") != string::npos )
                        {
                            p_p_c4_board[(size-1)-stabilizer][drop-1] = "IxI";
                            break;
                        }
                    }

                }

            }



    }
return;
}

bool check_win_1(string **p_p_c4_board, int size)
{
    //CHECKS ROWS
    for (int i = size-1; i >= 0 ;)
    {
    int j = 0;
        for (; j < size-3; )
        {
            if (p_p_c4_board[i][j].find("IoI") != string::npos )
            {
                ++j;

                if (p_p_c4_board[i][j].find("IoI") != string::npos)
                {
                    ++j;
                }
                else
                {
                    ++j;
                    continue;
                }
                    if (p_p_c4_board[i][j].find("IoI") != string::npos)
                    {
                        ++j;
                    }
                    else
                    {
                        ++j;
                        continue;
                    }

                        if (p_p_c4_board[i][j].find("IoI") != string::npos)
                        {
                            return true;
                        }
                        else
                        {
                            continue;
                        }

            }
            else
            {
                ++j;
                continue;
            }
        }
    --i;
    }

    //CHECKS COLUMNS
    for (int j = 0; j <= size-1 ;)
    {
        for (int i = size-1; i > 3; )
        {
            if (p_p_c4_board[i][j].find("IoI") != string::npos )
            {
                --i;

                if (p_p_c4_board[i][j].find("IoI") != string::npos)
                {
                    --i;
                }
                else
                {
                    --i;
                    continue;
                }
                    if (p_p_c4_board[i][j].find("IoI") != string::npos)
                    {
                        --i;
                    }
                    else
                    {
                        --i;
                        continue;
                    }

                        if (p_p_c4_board[i][j].find("IoI") != string::npos)
                        {
                            return true;
                        }
                        else
                        {
                            continue;
                        }

            }
            else
            {
                --i;
                continue;
            }
        }
    ++j;
    }

    //CHECKS ASCENDING DIAGONALS
    for (int i = size-1; i > 2; )
    {

        for (int j = 0; j < size-3 ; ++j)
        {
            int temp_1 = i;
            int temp_2 = j;
            if (p_p_c4_board[i][j].find("IoI") != string::npos )
            {
                ++j;
                --i;

                if (p_p_c4_board[i][j].find("IoI") != string::npos)
                {
                    ++j;
                    --i;
                }
                else
                {
                    i = temp_1; //Act as resets
                    j = temp_2;
                    continue;
                }
                    if (p_p_c4_board[i][j].find("IoI") != string::npos)
                    {
                        ++j;
                        --i;
                    }
                    else
                    {
                        i = temp_1;
                        j = temp_2;
                        continue;
                    }

                        if (p_p_c4_board[i][j].find("IoI") != string::npos)
                        {
                            return true;
                        }
                        else
                        {
                            continue;
                        }

            }
            else
            {
                continue;
            }
        }
    --i;
    }

    //CHECKS DESCENDING DIAGONALS
    for (int i = size-4; i >= 0; )
    {

        for (int j = 0; j <= size-4 ; ++j)
        {
            int temp_1 = i;
            int temp_2 = j;
            if (p_p_c4_board[i][j].find("IoI") != string::npos )
            {
                ++j;
                ++i;

                if (p_p_c4_board[i][j].find("IoI") != string::npos)
                {
                    ++j;
                    ++i;
                }
                else
                {
                    i = temp_1; //Act as resets
                    j = temp_2;
                    continue;
                }
                    if (p_p_c4_board[i][j].find("IoI") != string::npos)
                    {
                        ++j;
                        ++i;
                    }
                    else
                    {
                        i = temp_1;
                        j = temp_2;
                        continue;
                    }

                        if (p_p_c4_board[i][j].find("IoI") != string::npos)
                        {
                            return true;
                        }
                        else
                        {
                            i = temp_1;
                            j = temp_2;
                            continue;
                        }

            }
            else
            {
                continue;
            }
        }
    --i;
    }

return false;
}


bool check_win_2(string **p_p_c4_board, int size)
{
    //CHECKS ROWS
    for (int i = size-1; i >= 0 ;--i)
    {
        for (int j = 0; j < size-3; )
        {
            if (p_p_c4_board[i][j].find("IxI") != string::npos)
            {
                ++j;

                if (p_p_c4_board[i][j].find("IxI") != string::npos)
                {
                    ++j;
                }
                else
                {
                    ++j;
                    continue;
                }
                    if (p_p_c4_board[i][j].find("IxI") != string::npos)
                    {
                        ++j;
                    }
                    else
                    {
                        ++j;
                        continue;
                    }

                        if (p_p_c4_board[i][j].find("IxI") != string::npos)
                        {
                            return true;
                        }

            }
            else
            {
                ++j;
                continue;
            }
        }
    }

    //CHECKS COLUMNS
    for (int j = 0; j <= size-1 ;)
    {
        for (int i = size-1; i > 3; )
        {
            if (p_p_c4_board[i][j].find("IxI") != string::npos )
            {
                --i;

                if (p_p_c4_board[i][j].find("IxI") != string::npos)
                {
                    --i;
                }
                else
                {
                    --i;
                    continue;
                }
                    if (p_p_c4_board[i][j].find("IxI") != string::npos)
                    {
                        --i;
                    }
                    else
                    {
                        --i;
                        continue;
                    }

                        if (p_p_c4_board[i][j].find("IxI") != string::npos)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }

            }
            else
            {
                --i;
                continue;
            }
        }
    ++j;
    }

    //CHECKS ASCENDING DIAGONALS
    for (int i = size-1; i > 2; )
    {

        for (int j = 0; j < size-3 ; ++j)
        {
            int temp_1 = i;
            int temp_2 = j;
            if (p_p_c4_board[i][j].find("IxI") != string::npos )
            {
                ++j;
                --i;

                if (p_p_c4_board[i][j].find("IxI") != string::npos)
                {
                    ++j;
                    --i;
                }
                else
                {
                    i = temp_1; //Act as resets
                    j = temp_2;
                    continue;
                }
                    if (p_p_c4_board[i][j].find("IxI") != string::npos)
                    {
                        ++j;
                        --i;
                    }
                    else
                    {
                        i = temp_1;
                        j = temp_2;
                        continue;
                    }

                        if (p_p_c4_board[i][j].find("IxI") != string::npos)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }

            }
            else
            {
                continue;
            }
        }
    --i;
    }

    //CHECKS DESCENDING DIAGONALS
    for (int i = size-4; i >= 0; )
    {

        for (int j = 0; j <= size-4 ; ++j)
        {
            int temp_1 = i;
            int temp_2 = j;
            if (p_p_c4_board[i][j].find("IxI") != string::npos )
            {
                ++j;
                ++i;

                if (p_p_c4_board[i][j].find("IxI") != string::npos)
                {
                    ++j;
                    ++i;
                }
                else
                {
                    i = temp_1; //Act as resets
                    j = temp_2;
                    continue;
                }
                    if (p_p_c4_board[i][j].find("IxI") != string::npos)
                    {
                        ++j;
                        ++i;
                    }
                    else
                    {
                        i = temp_1;
                        j = temp_2;
                        continue;
                    }

                        if (p_p_c4_board[i][j].find("IxI") != string::npos)
                        {
                            return true;
                        }
                        else
                        {
                            i = temp_1;
                            j = temp_2;
                            continue;
                        }

            }
            else
            {
                continue;
            }
        }
    --i;
    }


return false;
}

bool check_full(string **p_p_c4_board, int size)
{
    for (int i = 0; i == 0; ++i)
    {
        for (int j = 0; j < size ;++j)
        {
            if (p_p_c4_board[i][j].find("I I") != string::npos)
            {
                return false;
            }

            else if (p_p_c4_board[i][j].find("I I") == string::npos)
            {
                continue;
            }
        }
    }

    return true;
}

int main()
{
    bool gameloop = true;

    char you = 'o';
    char him = 'x';

    cout<<"\tLet's Play Connect Four!!!";
    cout<<endl;
    int size;

    while (gameloop == true)
    {



    cout<<"1 - 4x4";
    cout<<endl;
    cout<<"2 - 6x6";
    cout<<endl;
    cout<<"3 - 8x8";
    cout<<endl;
    cout<<"Please select board size: ";
    cin>>size;

    if (size != 1 && size != 2 && size != 3)
    {
        cout<<endl;
        cout<<"Invalid Choice!";
        cout<<endl;
        continue;
    }

    if (size == 1)
    {
        size = 4;
        cout<<"You have chosen the 4x4 board!";
        cout<<endl;
        break;
    }

    else if (size == 2)
    {
        size = 6;
        cout<<"You have chosen the 6x6 board!";
        cout<<endl;
        gameloop = false;
    }

    else if (size == 3)
    {
        size = 8;
        cout<<"You have chosen the 8x8 board!";
        cout<<endl;
        gameloop = false;
    }

    }

    cout<<endl;

    string **p_p_c4_board;
    p_p_c4_board = new string *[size];

    for (int i = 0; i < size; ++i)
    {
        p_p_c4_board[i] = new string[size];
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            p_p_c4_board[i][j] = "I I";
        }
    }

    display(p_p_c4_board, size);



    do
    {

    player_1(p_p_c4_board, you, size);
    display(p_p_c4_board, size);
    if (check_win_1(p_p_c4_board, size) == true)
    {
        cout<<endl;
        cout<<"Player 1 WINS!";
        cout<<endl;
        break;
    }
    else if (check_full(p_p_c4_board, size) == true)
    {
        cout<<endl;
        cout<<"The board is full! Nobody Wins!";
        cout<<endl;
        break;
    }

    player_2(p_p_c4_board, him, size);
    display(p_p_c4_board, size);
    if (check_win_1(p_p_c4_board, size) == true)
    {
        cout<<endl;
        cout<<"Player 2 WINS!";
        cout<<endl;
        break;
    }
    else if (check_full(p_p_c4_board, size) == true)
    {
        cout<<endl;
        cout<<"The board is full! Nobody Wins!";
        cout<<endl;
        break;
    }

    } while(true);

    for(int i = 0; i < size; ++i)
    {
        delete [] p_p_c4_board[i];
    }

    delete [] p_p_c4_board;
}
