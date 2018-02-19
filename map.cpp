#include <iostream>


// on d�finit le niveau � l'aide de num�ro de tuiles
const int level[] =
{
	39 , 39 , 39 , 39 , 55 , 56 , 57 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 30 , 2  , 179, 180, 179, 180, 179, 180, 179, 180, 179, 180, 179, 180, 179, 180, 2  , 93 , 94 , 94 , 94 , 94 , 94 , 94 , 94 , 94 , 94 , 94 , 94 , 94 , 95 , 103, 103, 193,
	28 , 17 , 28 , 17 , 60 , 61 , 62 , 20 , 28 , 17 , 17 , 28 , 28 , 28 , 17 , 28 , 28 , 179, 189, 190, 189, 190, 189, 190, 189, 190, 189, 190, 189, 190, 189, 190, 180, 99 , 107, 131, 100, 100, 150, 100, 100, 100, 150, 100, 100, 100, 101, 103, 103, 193,
	19 , 18 , 18 , 18 , 68 , 69 , 70 , 18 , 18 , 18 , 19 , 18 , 18 , 18 , 19 , 18 , 35 , 187, 191, 192, 191, 192, 191, 192, 191, 192, 191, 192, 191, 192, 191, 192, 188, 99 , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 121, 122, 101, 103, 103, 193,
	2  , 2  , 12 , 2  , 47 , 71 , 45 , 2  , 2  , 12 , 2  , 2  , 2  , 2  , 2  , 12 , 2  , 179, 189, 190, 189, 190, 189, 190, 189, 190, 189, 190, 189, 190, 189, 190, 180, 99 , 100, 100, 151, 100, 100, 100, 100, 100, 100, 100, 125, 126, 101, 103, 103, 193,
	2  , 2  , 2  , 9  , 47 , 46 , 45 , 9  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 187, 191, 192, 191, 192, 191, 192, 191, 192, 191, 192, 191, 192, 191, 192, 188, 99 , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 101, 103, 103, 193,
	2  , 2  , 49 , 51 , 52 , 46 , 50 , 51 , 64 , 51 , 51 , 51 , 48 , 2  , 2  , 2  , 6  , 179, 189, 190, 189, 190, 189, 190, 189, 190, 189, 190, 189, 190, 189, 190, 180, 99 , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 127, 101, 103, 103, 193,
	2  , 9  , 47 , 46 , 63 , 46 , 46 , 46 , 64 , 46 , 46 , 46 , 45 , 12 , 2  , 2  , 2  , 187, 191, 192, 191, 192, 191, 192, 191, 192, 191, 192, 191, 192, 191, 192, 188, 99 , 107, 100, 100, 100, 100, 100, 151, 100, 100, 100, 100, 100, 101, 103, 103, 64 ,
	6  , 9  , 47 , 46 , 40 , 41 , 41 , 41 , 64 , 41 , 42 , 46 , 45 , 9  , 2  , 2  , 2  , 2  , 187, 188, 187, 188, 187, 188, 187, 188, 187, 188, 187, 188, 187, 188, 2  , 99 , 107, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 101, 103, 103, 64 ,
	2  , 2  , 47 , 46 , 45 , 2  , 2  , 2  , 2  , 6  , 47 , 63 , 45 , 2  , 9  , 2  , 2  , 2  , 2  , 2  , 6  , 2  , 2  , 2  , 2  , 2  , 2  , 6  , 2  , 2  , 2  , 2  , 2  , 99 , 100, 100, 100, 121, 122, 100, 100, 100, 100, 100, 100, 100, 101, 103, 103, 64 ,
	2  , 2  , 53 , 53 , 53 , 2  , 2  , 2  , 2  , 9  , 47 , 46 , 50 , 51 , 51 , 51 , 48 , 2  , 2  , 2  , 2  , 2  , 2  , 12 , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 99 , 100, 100, 100, 125, 126, 100, 100, 100, 121, 122, 100, 100, 101, 103, 103, 197,
	51 , 51 , 52 , 46 , 45 , 6  , 2  , 12 , 2  , 2  , 47 , 46 , 46 , 71 , 46 , 46 , 45 , 9  , 2  , 2  , 2  , 2  , 6  , 2  , 2  , 2  , 6  , 6  , 2  , 2  , 12 , 2  , 2  , 99 , 100, 100, 100, 100, 100, 100, 100, 100, 125, 126, 100, 100, 101, 103, 103, 193,
	63 , 71 , 46 , 46 , 45 , 2  , 2  , 2  , 2  , 2  , 2  , 41 , 41 , 41 , 42 , 46 , 45 , 15 , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 6  , 6  , 2  , 2  , 2  , 2  , 2  , 99 , 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 151, 101, 103, 103, 193,
	46 , 40 , 41 , 41 , 9  , 2  , 2  , 15 , 2  , 2  , 2  , 2  , 2  , 2  , 53 , 53 , 53 , 2  , 2  , 12 , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  , 6  , 99 , 100, 107, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 101, 103, 103, 193,
	56 , 57 , 39 , 39 , 39 , 39 , 80 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 55 , 56 , 57 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 80 , 39 , 39 , 39 , 39 , 39 , 39 , 30 , 99 , 131, 100, 100, 150, 150, 100, 100, 100, 150, 150, 100, 107, 101, 103, 103, 193,
	61 , 62 , 28 , 17 , 28 , 17 , 92 , 17 , 17 , 17 , 20 , 17 , 17 , 20 , 60 , 61 , 62 , 17 , 17 , 20 , 17 , 17 , 17 , 17 , 17 , 92 , 17 , 17 , 28 , 28 , 17 , 17 , 17 , 143, 143, 143, 143, 143, 143, 119, 100, 120, 143, 143, 143, 143, 143, 103, 103, 193,
	61 , 62 , 20 , 17 , 20 , 17 , 92 , 17 , 17 , 17 , 17 , 17 , 17 , 28 , 60 , 61 , 62 , 20 , 17 , 17 , 17 , 17 , 17 , 20 , 17 , 92 , 17 , 17 , 28 , 28 , 17 , 17 , 17 , 103, 103, 103, 103, 103, 103, 123, 100, 124, 103, 103, 103, 103, 103, 103, 103, 103,
	69 , 157, 25 , 24 , 25 , 25 , 86 , 16 , 25 , 25 , 25 , 16 , 25 , 25 , 156, 69 , 157, 25 , 16 , 16 , 25 , 25 , 25 , 25 , 25 , 86 , 25 , 25 , 24 , 25 , 25 , 16 , 33 , 109, 109, 109, 109, 109, 109, 128, 100, 129, 109, 109, 109, 109, 109, 109, 109, 109,
	46 , 168, 10 , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 7  , 1  , 1  , 1  , 167, 46 , 168, 1  , 1  , 10 , 1  , 1  , 1  , 1  , 1  , 1  , 13 , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 4  , 4  , 4  , 4  , 13 , 1  , 1  , 1  , 1  , 4  , 4  , 4  , 7  , 1  , 1  ,
	46 , 168, 1  , 1  , 1  , 1  , 161, 1  , 1  , 1  , 1  , 7  , 1  , 13 , 167, 71 , 168, 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 10 , 1  , 1  , 1  , 1  , 4  , 4  , 4  , 4  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 10 ,
	46 , 168, 1  , 7  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 53 , 53 , 53 , 1  , 1  , 7  , 161, 161, 1  , 1  , 10 , 1  , 1  , 1  , 1  , 7  , 1  , 1  , 1  , 1  , 1  , 161, 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 161, 1  , 1  , 1  , 1  ,
	63 , 168, 1  , 1  , 1  , 1  , 1  , 1  , 1  , 10 , 1  , 1  , 1  , 1  , 167, 63 , 168, 1  , 1  , 1  , 161, 161, 1  , 1  , 1  , 1  , 4  , 4  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 7  , 1  , 1  , 1  , 10 , 10 , 1  , 1  , 1  , 1  , 1  ,
	46 , 168, 1  , 161, 1  , 1  , 7  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 167, 46 , 168, 1  , 4  , 1  , 1  , 1  , 1  , 7  , 1  , 1  , 4  , 4  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 10 , 10 , 1  , 7  ,
	46 , 168, 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 171, 169, 170, 46 , 168, 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 10 , 10 , 10 , 10 , 10 ,
	46 , 168, 1  , 1  , 7  , 1  , 10 , 1  , 1  , 1  , 1  , 1  , 167, 46 , 63 , 46 , 168, 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 161, 1  , 1  , 1  , 7  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 10 , 10 , 10 , 10 , 10 ,
	46 , 196, 159, 158, 159, 158, 159, 158, 159, 1  , 1  , 1  , 167, 46 , 155, 172, 1  , 1  , 1  , 1  , 1  , 1  , 1  , 10 , 1  , 7  , 7  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 161, 1  , 1  , 1  , 1  , 1  , 10 , 1  , 10 , 10 , 10 ,
	196, 173, 174, 173, 174, 173, 174, 173, 174, 159, 7  , 1  , 167, 46 , 168, 1  , 1  , 1  , 10 , 1  , 1  , 1  , 1  , 1  , 7  , 7  , 7  , 7  , 175, 176, 175, 176, 175, 176, 175, 176, 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 10 , 10 , 10 ,
	165, 181, 182, 181, 182, 181, 182, 181, 182, 166, 1  , 1  , 167, 46 , 168, 10 , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 7  , 7  , 7  , 7  , 175, 177, 178, 177, 178, 177, 178, 177, 178, 176, 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 10 , 10 ,
	158, 173, 174, 173, 174, 173, 174, 173, 174, 159, 1  , 1  , 167, 63 , 168, 1  , 1  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 8  , 8  , 8  , 183, 185, 186, 185, 186, 185, 186, 185, 186, 184, 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 8  , 8  , 3  , 3  , 3  ,
	165, 181, 182, 181, 182, 181, 182, 181, 182, 166, 1  , 161, 167, 46 , 168, 1  , 1  , 5  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 5  , 8  , 175, 177, 178, 177, 178, 177, 178, 177, 178, 176, 3  , 5  , 3  , 8  , 3  , 3  , 3  , 3  , 3  , 8  , 3  , 11 , 3  ,
	158, 173, 174, 173, 174, 173, 174, 173, 174, 159, 1  , 1  , 167, 46 , 168, 1  , 1  , 3  , 3  , 5  , 3  , 3  , 3  , 3  , 11 , 3  , 8  , 183, 185, 186, 185, 186, 185, 186, 185, 186, 184, 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  ,
	165, 181, 182, 181, 182, 181, 182, 181, 182, 166, 1  , 1  , 167, 46 , 168, 161, 1  , 3  , 3  , 3  , 3  , 3  , 8  , 3  , 3  , 3  , 3  , 175, 177, 178, 177, 178, 177, 178, 177, 178, 176, 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 5  , 3  ,
	158, 173, 174, 173, 174, 173, 174, 173, 174, 159, 1  , 1  , 167, 46 , 168, 1  , 1  , 3  , 3  , 3  , 5  , 3  , 3  , 3  , 3  , 3  , 3  , 183, 185, 186, 185, 186, 185, 186, 185, 186, 184, 3  , 3  , 3  , 3  , 5  , 11 , 3  , 3  , 3  , 3  , 3  , 3  , 0  ,
	165, 181, 182, 181, 182, 181, 182, 181, 182, 166, 1  , 1  , 167, 46 , 168, 13 , 1  , 3  , 8  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 175, 177, 178, 177, 178, 177, 178, 177, 178, 176, 3  , 3  , 8  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 0  , 0  , 0  ,
	158, 173, 174, 173, 174, 173, 174, 173, 174, 159, 1  , 1  , 53 , 53 , 53 , 1  , 1  , 3  , 3  , 3  , 3  , 8  , 11 , 3  , 3  , 3  , 8  , 183, 185, 186, 185, 186, 185, 186, 185, 186, 184, 5  , 11 , 3  , 3  , 3  , 8  , 3  , 3  , 0  , 0  , 0  , 0  , 0  ,
	165, 181, 182, 181, 182, 181, 182, 181, 182, 166, 7  , 1  , 167, 46 , 168, 1  , 1  , 5  , 3  , 11 , 3  , 8  , 3  , 3  , 3  , 3  , 3  , 3  , 183, 184, 183, 184, 183, 184, 183, 184, 3  , 3  , 5  , 3  , 3  , 3  , 3  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	158, 173, 174, 173, 174, 173, 174, 173, 174, 159, 1  , 1  , 167, 46 , 168, 7  , 1  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 8  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	165, 181, 182, 181, 182, 181, 182, 181, 182, 166, 1  , 1  , 167, 71 , 168, 1  , 1  , 3  , 3  , 3  , 3  , 3  , 3  , 11 , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 8  , 3  , 3  , 3  , 3  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	158, 173, 174, 173, 174, 173, 174, 173, 174, 159, 7  , 1  , 167, 46 , 168, 1  , 10 , 3  , 3  , 3  , 8  , 8  , 8  , 3  , 3  , 3  , 3  , 11 , 3  , 3  , 3  , 5  , 3  , 3  , 3  , 3  , 3  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	165, 181, 182, 181, 182, 181, 182, 181, 182, 166, 1  , 1  , 167, 71 , 168, 1  , 1  , 3  , 8  , 8  , 8  , 8  , 8  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	1  , 165, 166, 165, 166, 165, 166, 165, 166, 1  , 1  , 1  , 167, 46 , 168, 1  , 1  , 3  , 8  , 8  , 8  , 8  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 3  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
};


// on ref�nifit le niveau pour l'aide � la collision en mettant les tuiles o� le personnage
// peut marcher � la valeur 0 et celles o� il ne peut pas � 5
const int level_collision[] =
{
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  ,
	0  , 0  , 1  , 0  , 1  , 1  , 1  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  ,
	0  , 0  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  ,
	0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  ,
	0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 9  , 9  , 9  ,
	0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 9  , 9  , 9  ,
	0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 9  , 9  , 9  ,
	0  , 0  , 8  , 8  , 8  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 1  , 1  , 0  , 0  , 0  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 8  , 8  , 8  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  ,
	1  , 1  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 0  , 0  , 1  , 1  , 0  , 8  , 0  , 1  , 1  , 0  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 8  , 8  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 8  , 8  , 8  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  ,
	1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 8  , 8  , 8  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 0  , 0  , 0  , 0  , 0  ,
	1  , 1  , 8  , 8  , 8  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 0  , 0  ,
	1  , 1  , 8  , 8  , 8  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 8  , 8  , 8  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 0  , 0  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 1  , 1  , 1  , 
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 8  , 8  , 8  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 8  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 0  , 1  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
	1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 8  , 0  , 0  , 1  , 1  , 1  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  , 1  ,
};