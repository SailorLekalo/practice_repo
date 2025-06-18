class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        counter = 0
        if flowerbed[0]==0:
            if len(flowerbed) == 1:
                flowerbed[0]=1
                counter+=1
            elif flowerbed[1]==0:
                flowerbed[0]=1
                counter+=1
        for i in range(1,len(flowerbed)-1):
            if flowerbed[i] == 0:
                if flowerbed[i-1]==0 and flowerbed[i+1]==0:
                    flowerbed[i]=1
                    counter +=1
        if flowerbed[len(flowerbed)-1]==0 and flowerbed[len(flowerbed)-2]==0:
            flowerbed[len(flowerbed)-1]=1
            counter+=1
        return (counter>=n)
