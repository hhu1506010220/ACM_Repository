#include <stdio.h>  
#include <string.h>  
  
#define MAXSIZE     55*55  
  
int     r, c, xCnt, yCnt ;  
int     link[MAXSIZE] ;  
bool    cover[MAXSIZE] ;  
char    map[55][55] ;  
bool    graph[MAXSIZE][MAXSIZE] ;  
int     mapx[55][55], mapy[55][55] ;  
  
bool find (int cur)  
{  
    int i ;  
    for (i = 1 ; i <= xCnt ; ++i)  
    {  
        if (cover[i] == false && graph[cur][i] == true)  
        {  
            cover[i] = true ;  
            if (link[i] == 0 || find (link[i]))  
            {  
                link[i] = cur ;  
                return true ;  
            }  
        }  
    }  
    return false ;  
}  
  
int getSum ()  
{  
    int i ;  
    int sum ;  
    sum = 0 ;  
  
    memset (link, 0, sizeof (link)) ;  
    for (i = 1 ; i <= yCnt ; ++i)  
    {  
        memset (cover, 0, sizeof (cover)) ;  
        sum += find (i) ;  
    }  
    return sum ;  
}  
  
int main ()  
{  
    int i, j ;  
  
    while (~scanf ("%d%d", &r, &c))  
    {  
        for (i = 0 ; i < r ; ++i)  
            scanf ("%s", map[i]) ;  
  
        memset (mapx, 0, sizeof (mapx)) ;  
        memset (mapy, 0, sizeof (mapy)) ;  
        yCnt = 0 ;  
        for (i = 0 ; i < r ; ++i)  
            for (j = 0 ; j < c ; ++j)  
                if (map[i][j] == '*')  
                {  
                    ++yCnt ;  
                    while (j < c && map[i][j] == '*')  
                    {  
                        mapy[i][j] = yCnt ;  
                        ++j ;  
                    }  
                }  
        xCnt = 0 ;  
        for (j = 0 ; j < c ; ++j)  
            for (i = 0 ; i < r ; ++i)  
                if (map[i][j] == '*')  
                {  
                    ++xCnt ;  
                    while (i < r && map[i][j] == '*')  
                    {  
                        mapx[i][j] = xCnt ;  
                        ++i ;  
                    }  
                }  
  
        memset (graph, 0, sizeof (graph)) ;  
        for (i = 0 ; i < r ; ++i)  
            for (j = 0 ; j < c ; ++j)  
                graph[mapy[i][j]][mapx[i][j]] = 1 ;  
  
        printf ("%d\n", getSum ()) ;  
    }  
    return 0 ;  
}  
