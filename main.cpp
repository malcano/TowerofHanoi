#include "std_lib_facilities.h"
//#include <stdio.h>

using namespace std;


void additionalPreset(int size, vector<vector<int>>& row, vector<int>& tower) //additional function - preset
{
    int k= 0;
    for (int i = 0; i < size*2*3; i++)
    {
        row.push_back(tower);
    }//reset row

    for (int i = size; i > 0; i--)
    {
        for(int j=0;j<(size-k)*2;j++)
        {
            row[j+k].push_back(i);
            //cout<<"preset success!"<<endl;
        }
        k++;
    }//set Disk

}

void additionalPrintTowers(vector<vector<int>>& row, int size)
{
    for (unsigned int i = 0; i < size*2*3; i++)//row.size()
    {
        cout << "#";
        for (unsigned int j = 0; j < row[i].size(); j++)
        {
            cout << "|";
        }
        cout << "\n";
        if((i+1)%(size*2)==0)
        {
            cout << "\n";
        }
    }//Print tower
    cout << "\n";
    
}

void testPrint(vector<vector<int>>& row, int size)
{
    for (unsigned int i = 0; i < size*2*3; i++)//row.size()
    {
        cout << "#";
        for (unsigned int j = 0; j < row[i].size(); j++)
        {
            cout << "|";
        }
        cout << "\n";
        if((i+1)%(size*2)==0)
        {
            cout << "\n";
        }
    }//Print tower
    cout << "\n";
   
}

bool additionalIsMoveAllowed(int fromWhere, int toWhere, int size, vector<vector<int>>& row)//
{
    if (fromWhere <= 0 || toWhere <= 0 || fromWhere==toWhere ||fromWhere>3 || toWhere>3)//input must be bigger than 0 and smaller than 4
        return false;
    else if (row[(fromWhere*size*2-size)].size() == 0)//disk must be moveable
        return false;
    else if (row[toWhere*size*2-size].size() > 0)//when the disk is already set
    {
        if (row[toWhere*size*2-size][row[toWhere*size*2-size - 1].size() - 1] < row[fromWhere*size*2-size][row[fromWhere*size*2-size - 1].size() - 1])//the disk which would be moved must be smaller than the disk below
            return false;
    }
    return true;
}


void additionalMoveDisk(int fromWhere, int toWhere, int size, vector<vector<int>> &row)
{
    int topdisk = 0 ;//size로 봐서 가장 긴거
    int disknum = 0;
    for (unsigned int i = (fromWhere-1)*size*2; i < fromWhere*size*2; i++)//row.size()
    {
        if(row[i].size()>topdisk)
        {
            topdisk=row[i].size();
        }
        
    }
    
    for (unsigned int i = (fromWhere-1)*size*2; i < fromWhere*size*2; i++)//row.size()
    {
        if(row[i].size()==topdisk)
        {
            disknum = row[i].back();
            row[i].pop_back();
        }
    }
    
    
    for (unsigned int i = size+size*2*(toWhere-1)-disknum; i < size+size*2*(toWhere-1)+disknum; i++)//row.size()
    {
        row[i].push_back(disknum);
    }
   
    //cout<<"rowsize: "<<row.size()<<endl;

}


void Preset(int size, vector<vector<int>>& row, vector<int>& tower)
{
    for (int i = 0; i < 3; i++)
    {
        row.push_back(tower);
    }//reset row

    for (int i = size; i > 0; i--)
    {
        row[0].push_back(i);
    }//set Disk

}


void PrintTowers(vector<vector<int>>& row)
{
    for (unsigned int i = 0; i < 3; i++)//rod == 3
    {
        cout << "[" << i + 1 << "]";
        for (unsigned int j = 0; j < row[i].size(); j++)
            cout << row[i][j] << " ";
        cout << "\n";
    }//Print tower
    cout << "\n";
}

bool IsMoveAllowed(int fromWhere, int toWhere, int size, vector<vector<int>>& row)//
{

    if (fromWhere <= 0 || toWhere <= 0 || fromWhere==toWhere ||fromWhere>3 || toWhere>3)//input must be bigger than 0 and smaller than 4
        return false;
    else if (row[fromWhere - 1].size() == 0)//disk must be moveable
        return false;
    else if (row[toWhere - 1].size() > 0)//when a disk is already set
    {
        if (row[toWhere - 1][row[toWhere - 1].size() - 1] < row[fromWhere - 1][row[fromWhere - 1].size() - 1])//the disk which wants to move must be smaller than the disk below
            return false;
    }
    
    return true;
}

void MoveDisk(int fromWhere, int toWhere, vector<vector<int>> &row)
{
    int disk;
    disk = row[fromWhere-1][row[fromWhere-1].size() - 1];//save disk
    row[fromWhere-1].pop_back();
    row[toWhere-1].push_back(disk);
}

bool Replay(int playagain)
{
    
    return true;
}


void Path(int size, int fromWhere, int toWhere, vector<vector<int>> &row)
{
    additionalMoveDisk(fromWhere, toWhere, size, row);
    additionalPrintTowers(row, size);
}
void autoHanoi(int disk, int size, int fromWhere, int toWhere, int temp, vector<vector<int>> &row, int &count)
{
    if (size == 1)
    {
        Path(disk, fromWhere, toWhere, row);
    }
    else
    {
        autoHanoi(disk,size-1, fromWhere, temp, toWhere, row, count);
        count++;
        Path(disk, fromWhere, toWhere, row);
        autoHanoi(disk, size-1, temp, toWhere, fromWhere,row, count);
        count++;

    }
}


int main()
{

    vector<vector<int>> row = {};
    vector<int> tower = {};
    vector<int> fromWheretoWhere(2);
    
    int size = 3;
    int count = 1;
    int fromWhere = 0;
    int toWhere = 0;
    char Playagain = 0;
    char AdditionalFunction = 0;
    
    while (1)
    {
        cout << "Do you want to play with additional function? (Y/N/A (A for auto)): ";
        cin >> AdditionalFunction;

        if (AdditionalFunction == 'y' || AdditionalFunction == 'Y')
            break;
        else if (AdditionalFunction == 'n' || AdditionalFunction == 'N')
            break;
        else if (AdditionalFunction == 'a' || AdditionalFunction == 'A')
            break;
        else
        {
            cout << "Incorrect input! Try again!\n";
            continue;
        }
    }///ask additional function
    

    while (AdditionalFunction == 'y' || AdditionalFunction == 'Y') //additional function
    {
        count = 1;

        while (1)
        {
            cout << "How many disks do you want?:  ";
            cin >> size;

            if (size > 0)
                break;
            else
            {
                cout << "Incorrect input! Try again!\n";
                continue;
            }
        }
        additionalPreset(size, row, tower);
        additionalPrintTowers(row, size);

        while (1)
        {
            cout << "\n[" << count << "]" << " From Which tower will you move a disk to which tower? (from=[1|2|3], to=[1|2|3]): ";
            cin >> fromWhere >> toWhere;
            
            
            
            if (additionalIsMoveAllowed(fromWhere, toWhere, size, row) == false)
            {
                cout << "=>Move failed! \n";
                continue;
            }
            // testMoveDisk(fromWhere, toWhere, size, row);
            additionalMoveDisk(fromWhere, toWhere, size, row);
            cout << "=>Move succeeded! \n";
            additionalPrintTowers(row,size);
                        
            
            //cin>> size;//eliminate it later
            
            
            
            if (row[size*2*3 - size].size() == size)//clear
                break;
            count++;

            
        }

        
        cout << "Congratulation! You solved in in " << count << " moves!\n";

        while (1)
        {
            cout << "Do you want to play again?(Y/N): ";
            cin >> Playagain;

            if (Playagain == 'y' || Playagain == 'Y')
                break;
            else if (Playagain == 'n' || Playagain == 'N')
                break;
            else
            {
                cout << "Incorrect input! Try again!\n";
                continue;
            }
        }

        if (Playagain == 'y' || Playagain == 'Y')
        {
            row.clear();
            cout << "\n";

            continue;
        }
        else if (Playagain == 'n' || Playagain == 'N')
            break;

    }
    
    
    while (AdditionalFunction == 'a' || AdditionalFunction == 'A') //auto
    {
        count = 1;

        while (1)
        {
            cout << "How many disks do you want?:  ";
            cin >> size;

            if (size > 0)
                break;
            else
            {
                cout << "Incorrect input! Try again!\n";
                continue;
            }
        }

        additionalPreset(size, row, tower);
        additionalPrintTowers(row, size);


        while (1)
        {
            autoHanoi(size, size, 1, 3, 2, row, count);
            
            if (row[size*2*3 - size].size() == size)//clear
                break;
        }

        cout << "Congratulation! You solved in in " << count << " moves!\n";

        while (1)
        {
            cout << "Do you want to play again?(Y/N): ";
            cin >> Playagain;

            if (Playagain == 'y' || Playagain == 'Y')
                break;
            else if (Playagain == 'n' || Playagain == 'N')
                break;
            else
            {
                cout << "Incorrect input! Try again!\n";
                continue;
            }
        }

        if (Playagain == 'y' || Playagain == 'Y')
        {
            row.clear();
            cout << "\n";

            continue;
        }
        else if (Playagain == 'n' || Playagain == 'N')
            break;

    }
    
/*
 main assignment below
 */

    while (AdditionalFunction == 'n' || AdditionalFunction == 'N') //non additional function
    {
        count = 1;
        Preset(size, row, tower);
        PrintTowers(row);



        while (1)
        {
            cout << "\n[" << count << "]" << " From Which tower will you move a disk to which tower? (from=[1|2|3], to=[1|2|3]): ";
            cin >> fromWhere >> toWhere;
            if (IsMoveAllowed(fromWhere, toWhere, size, row) == false)
            {
                cout << "=>Move failed! \n";
                continue;
            }
            MoveDisk(fromWhere, toWhere, row);

            cout << "=>Move succeeded! \n";
            PrintTowers(row);

            if (row[size - 1].size() == size)
                break;
            count++;
        }

        cout << "Congratulation! You solved in in " << count << " moves!\n";
        
        while (1)
        {
            cout << "Do you want to play again?(Y/N): ";
            cin >> Playagain;

            if (Playagain == 'y' || Playagain == 'Y')
                break;
            else if (Playagain == 'n' || Playagain == 'N')
                break;
            else
            {
                cout << "Incorrect input! Try again!\n";
                continue;
            }
        }
            
        if (Playagain == 'y' || Playagain == 'Y')
        {
            row.clear();
            cout << "\n";

            continue;
        }
        else if (Playagain == 'n' || Playagain == 'N')
            break;

    }
    
    return 0;
}
