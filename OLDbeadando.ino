
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Assuming array is a 3D array and arrayLength is its length
bool array[frames][16][12];
int arrayLength = sizeof(array) / sizeof(array[0]);
int frame = 0;

void setup()
{
    lcd.begin(16, 2);
}

void loop()
{
    // Assuming array is an array and arrayLength is its length
    while (frame != arrayLength)
    {
        for(int i2 = 0; i2 < 4; i2++)
        {
            for(int j2 = 0; j2 < 2; j2++)
            {
                bool characterMaterial[5][8] = selectedPartOfFrame(i2,j2);
                byte theCharacter[8] = characterCreation(i2,j2,characterMaterial);
                customCharacterCreation(i2,j2,theCharacter);
            }
        }
        for(int i5 = 0; i5 < 4; i5++)
        {
            for(int j5 = 0; j5 < 2; j5++)
            {
                lcd.setCursor(i5,j5);
                lcd.write(i5+j5*4);
            }
        }
        frame++;
        delay(33); // Delay for 30 frames per second
    }
}

bool** selectedPartOfFrame(int row, int column)
{
    static bool theThingWeReturn[5][8];
    for(int i3 = 0; i3 < 5; i3++)
        for(int j3 = 0; j3 < 8; j3++)
        {
            theThingWeReturn[i3][j3] = array[frame][row*5+i3][column*8+j3];
        }
    return theThingWeReturn;
}

byte* characterCreation(int row, int column, bool characterMaterial[5][8])
{
    static byte charToReturn[8];
    for(int i4 = 0; i4 < 8; i4++)
    {
        charToReturn[i4] = B;
        for(int j4 = 0; j4 < 5; j4++)
        {
            charToReturn[i4] += characterMaterial[i4][j4];
        }
    }
    return charToReturn;
}

void customCharacterCreation(int row, int column, byte customCharacter[8])
{
    lcd.createChar(row*4+column, customCharacter);
}

while (array != array.GetLength(0))
{
    for(i2: 0-3)
    {
        for(j2: 0-1)
        {
            bool[,] characterMaterial = selectedPartOfFrame(i2,j2)
            byte[8] theCharacter = characterCreation(i2,j2,characterMaterial)
            customCharacterCreation(i2,j2,theCharacter)
        }
    }
    for(i5: 0-3)
    {
        for(j5:0-1)
        {
            setcursor(i5,j5)
            write(i5+j5*4)
        }
    }
    frame++
}
selectedPartOfFrame(row, column)
{
    bool[,] theThingWeReturn = new()
    for(i3: 0-4)
        for(j3: 0-7)
        {
            theThingWeReturn[i3,j3]= videoArray[frameNumber,row*5+i3, column*8+j3]
        }
    return theThingWeReturn
}
characterCreation(row,column,characterMaterial)
{
    byte[] charToReturn = new byte[8]
    for(i4: 0-7)
    {
       charToReturn[i].asString() = B
       for(j4: 0-4)
       {
            charToReturn[i].asString() +=characterMaterial[i,j]
       }
    }
    return charToReturn
}
customCharacterCreation(row,column,customCharacter)
{
    createCustomChar(row*4+column,customCharacter)
}

