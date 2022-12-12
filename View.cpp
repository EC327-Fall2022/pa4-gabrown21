#include"View.h"
#include<iostream>

using namespace std;

View::View()
{
    size = 11;
    scale = 2;
    origin = Point2D();
}

bool View::GetSubscripts(int& outx,int& outy, Point2D loc)
{
    outy = (loc.y - origin.y)/scale;
    outx = (loc.x - origin.x)/scale;
    if(loc.x>20||loc.x<0||loc.y>20||loc.x<0)
    {
        cout<<"An object is outside display"<<endl;
        return false;
    }
    else
    {
        return true;
    }

}

void View::Clear()
{
    for(int i = 0; i<view_maxsize; i++)
    {
        for(int j = 0; j<view_maxsize;j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}
void View::Plot(GameObject* ptr)
{
    int outx;
    int outy;
    bool subs = GetSubscripts(outx,outy,ptr->GetLocation());
    if(subs == true)
    {
        if(ptr->GetState()==2)
        {
            grid[outx][outy][0] = '.';
            grid[outx][outy][1] = ' ';
        }
        else
        {
            if(grid[outx][outy][0] == '.')
            {
                ptr->DrawSelf(grid[outx][outy]);
            }
            else{
                    grid[outx][outy][0] = '*';
                    grid[outx][outy][1] = ' ';
            }
        }
    }  
}

void View::Draw()
{
    for(int j = size-1; j>= -1; j--)
    {
        for(int i = -1;i<=size -1;i++)
        {
            if(i == -1 && j%2 == 0)
            {
                cout<<j*2;
                if(j/5 == 0)
                {
                    cout<<" ";
                }
            }
            else if(i == -1 && j%2 != 0)
            {
                cout<<" ";
            }
            else if(j == -1 && i%2 == 0)
            {
                cout<<i*2;
                if(i/5 == 0)
                {
                    cout<<" ";
                }
                cout<<"  ";
            }
            if(i>= 0 && j>=0)
            {
                cout<<grid[i][j][0]<<grid[i][j][1];
            }
        }
        cout<<endl;
    }
}