#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
using namespace std;


class GuitarStuff {
    private:
                           // char Notes[12] = 
                           // 'E','F','F#','G','Ab','A','Bb','B','C','C#','D', 'Eb'
                           // {0,    1,       2,     3,       4,     5,       6,     7,     8,       9,     10,      11}
        char Notes[12][3] = {{'E'},{'F'},{'F','#'},{'G'},{'A','b'},{'A'},{'B','b'},{'B'}, {'C'},{'C','#'},{'D'},{'E','b'}};
                                //'C','G','D','A','E','B','F#','C#','G#','Ab','Bb','F'
    int CircleOfFifths[12] = { 9,  4, 11,  6,  1,  8,   3,  10,   5, 12 ,  7, 2};
        int Dorian[12] = {1, 0, 2, 3, 0, 2, 0, 2, 0, 2, 2, 0};
       int Aeolian[12] = {1, 0, 2, 2, 0, 2, 0, 2, 3, 0, 2, 0};
        int Lydian[12] = {2, 1, 0, 2, 0, 2, 0, 2, 2, 0, 2, 0};
        int Ionian[12] = {1, 0, 2, 0, 2, 3, 0, 2, 0, 2, 0, 2};
    int Mixolydian[12] = {1, 0, 2, 0, 2, 2, 0, 2, 0, 2, 3, 0};
      int Phyrgian[12] = {1, 3, 0, 2, 0, 2, 0, 2, 2, 0, 2, 0};
       int Locrian[12] = {1, 2, 0, 2, 0, 2, 3, 0, 2, 0, 2, 0};
    int MajorScale[12] = {1, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0};
    
    public:       //|     1  2  3  4  5  1  2  3, 4, 5, 1, 2


        int ChangeNote(int Note, int Change) {
            int ReturnValue;
            if (Note + Change > 11) {
                ReturnValue = ((Note + Change) % 12);
            } else if (Note + Change < 1) {
                ReturnValue = ((Note + Change) % 12);
            } else {
                ReturnValue = Note + Change;
            }
            return ReturnValue;
        }

        void PrintString(int String) {
            int StartingNote = 0;
            if (String == 1) {
                StartingNote = 0;
            } else if (String == 2) {
                StartingNote = 7;
            } else if (String == 3) {
                StartingNote = 3;
            } else if (String == 4) {
                StartingNote = 10;
            } else if (String == 5) {
                StartingNote = 5;
            } else if (String == 6 ) {
                StartingNote = 0;
            }
            int CurrentNote = StartingNote;
            cout << "<> " << Notes[CurrentNote] << "|";
            for (int i = 0; i < 12; i++) {
               
                CurrentNote = ChangeNote(CurrentNote, 1);
                cout << "-" << Notes[CurrentNote];
                if (Notes[CurrentNote][1] == 0) {
                    cout << "-";
                }
                cout << "-|";
            }
            cout << endl;
        }

        int FindStartingNote(int String) {
            int StartingNote = 0;
            if (String == 0) {
                StartingNote = 0;
            } else if (String == 1) {
                StartingNote = 7;
            } else if (String == 2) {
                StartingNote = 3;
            } else if (String == 3) {
                StartingNote = 10;
            } else if (String == 4) {
                StartingNote = 5;
            } else if (String == 5 ) {
                StartingNote = 0;
            }
            return StartingNote;
        }

        char* returnNumber(int i) {
            char* returnValue = new char[3];
            for(int i = 0; i < 3; i++) {
                returnValue[i] = 0;
            }
            if (i == 0) {
                returnValue[0] = '0';
            } else if (i == 1) {
                returnValue[0] = '1';
            } else if (i == 2) {
                returnValue[0] = '2';
            } else if (i == 3) {
                returnValue[0] = '3';
            } else if (i == 4) {
                returnValue[0] = '4';
            } else if (i == 5) {
                returnValue[0] = '5';
            } else if (i == 6) {
                returnValue[0] = '6';
            } else if (i == 7) {
                returnValue[0] = '7';
            } else if (i == 8) {
                returnValue[0] = '8';
            } else if (i == 9) {
                returnValue[0] = '9';
            } else if (i == 10) {
                returnValue[0] = '1';
                returnValue[1] = '0';
            } else if (i == 11) {
                returnValue[0] = '1';
                returnValue[1] = '1';
            } else if (i == 12) {
                returnValue[0] = '1';
                returnValue[1] = '2';
            } else if (i == 13) {
                returnValue[0] = '1';
                returnValue[1] = '3';
            } else if (i == 14) {
                returnValue[0] = '1';
                returnValue[1] = '4';
            } else if (i == 15) {
                returnValue[0] = '1';
                returnValue[1] = '5';
            } else if (i == 16) {
                returnValue[0] = '1';
                returnValue[1] = '6';
            } else {
                returnValue[0] = 'e';
            }
            return returnValue;
        }

        bool DetermineDistance(int Position1, int String1, int Position2, int String2) {
            //cout << "Determining" << endl;
            if (((abs(String1 - String2)*1.5) + (abs(Position1-Position2)*1.5)) > 5) {
                return false;
            } else {
                return true;
            }
            
        }

        int FindNoteOnScale(int Counter, int Position1, int Position2) {
            return 0;
        }

        int* FindScale(string Type) {
            int *Mode;
            if (Type == "Dorian") {
                Mode = Dorian;
            } else if (Type == "Aeolian") {
                Mode = Aeolian;
            } else if (Type == "Lydian") {
                Mode = Lydian; 
            } else if (Type == "Ionian") {
                Mode = Ionian;
            } else if (Type == "Mixolydian") {
                Mode = Mixolydian;
            } else if (Type == "Phyrgian") {
                Mode = Phyrgian;
            } else if (Type == "Locrian") {
                Mode = Locrian;
            } else {
                Mode = MajorScale;
            }
            return Mode;
        }

        int FindFretByNote(int String, int NoteNumber) {
            int StringNote = FindStartingNote(String);
            return StringNote+NoteNumber % 12;
        }

        int ReturnDifferentString(int String1) {
            int String2 = rand() % 6 + 1;
            while(String2 == String1) {
                String2 = rand() % 6 + 1;
            }
            return String2;
        }

        int* FindScaleOnString(int String, int* Mode) {
            int CurrentNote = FindStartingNote(String);
            int counter = 0;
            for(int i = 0; i < 12; i++) {
                if (Mode[CurrentNote] != 0) {
                    counter++;
                }
            }
            int* ReturnValue = new int[counter];
            int counter2 = 0;
            for(int i = 0; i < 12; i++) {
                if (Mode[CurrentNote] != 0) {
                    ReturnValue[counter2++] = i;
                }
            }
            return ReturnValue;
        }

        void PrintMode(int String = 0, string Type = "00", int Shift = 0, int ShiftedNote = 0) {
            int StartingNote = FindStartingNote(String);
            int* Mode = FindScale(Type);
            if (ShiftedNote != 0) {
                int *temp = new int[12];
                int marker = 0;
                while (Notes[Mode[marker]] != Notes[StartingNote]) {
                    if (marker > 11) {
                        marker = marker % 12;
                    }
                }
                
                for(int i = 0; i+marker < 12; i++) {
                    temp[i] = Mode[i+marker];
                }
                for(int i = 0; i < marker; i++) {
                    temp[i+marker] = Mode[i];
                }
                Mode = temp;
            }
            int CurrentNote = StartingNote;
            cout << ">";
            char seperation;
            if (Mode[CurrentNote] == 1) {
                seperation = '~';
            } else if (Mode[CurrentNote] == 2) {
                seperation = '-';
            } else if (Mode[CurrentNote] == 3) {
                seperation = '=';
            } else {
                seperation = '(';
            }
            if (Mode[CurrentNote] != 0) {
                if (seperation != '(') {
                    cout << seperation << Notes[ChangeNote(CurrentNote, Shift)] << seperation;
                    if (Notes[ChangeNote(CurrentNote, Shift)][1] == 0) {
                        cout << seperation;
                    }
                } else {
                    cout << seperation << Notes[ChangeNote(CurrentNote, Shift)] << ')';
                    if (Notes[ChangeNote(CurrentNote, Shift)][1] == 0) {
                        cout << ')';
                    }
                }
            } else {
                cout << "----";
            }
            cout <<  "< |";

            for (int i = 0; i < 11; i++) {
               
                seperation = 0;
                CurrentNote = ChangeNote(CurrentNote, 1);
                if (Mode[CurrentNote] == 1) {
                    seperation = '~';
                } else if (Mode[CurrentNote] == 2) {
                    seperation = '-';
                } else if (Mode[CurrentNote] == 3) {
                    seperation = '=';
                } 
                if (Mode[CurrentNote] != 0) {
                    cout << seperation << Notes[ChangeNote(CurrentNote, Shift)] << seperation;
                    if (Notes[ChangeNote(CurrentNote, Shift)][1] == 0) {
                        cout << seperation;
                    }
                } else {
                    cout << "----";
                }
                cout << "|";
            }
            cout << endl;
        }

        void PrintRandomProgression(string Type = "00", int Shift = 0, int ShiftedNote = 0) {
            int* mode = FindScale(Type);
            srand(time(NULL));
            int* collection = new int[12];
            int counter = 0;
            int String1;
            int OldString1;
            int Position1;
            int OldPosition1;
            int ScalePosition1;
            /*int String2;
            int Position2;
            int ScalePosition2;
            int String3;
            int Position3;
            int ScalePosition3;
            bool MultiNotes;*/
            cout << "Testing1" << endl;
            cout << "|";
            for(int i = 0; i < 12; i++) {
                if (mode[i] != 0) {
                    collection[counter++] = i;
                    cout << "-" << i << "-|";
                }
            }
            char** Progression = new char*[6];
            for(int i = 0; i < 6; i++) {
                Progression[i] = new char[68];
                Progression[i][0] = '>';
                Progression[i][1] = '<';
                Progression[i][2] = ' ';
                Progression[i][3] = '|';
            }
            
            int ProgressionCounter = 4;
            cout << "Testing3: " << ProgressionCounter << endl;
            for(int i = 0; i < counter; i++) {
                cout << collection[i] << endl;
            }

            while (ProgressionCounter < 80) {
                String1 = rand() % 6;
                ScalePosition1 = rand() % (counter);
                Position1 = FindFretByNote(String1, collection[ScalePosition1]);
                if (ProgressionCounter == 4) {
                    OldString1 = String1;
                    OldPosition1 = Position1;
                }
                //cout << String1 << " String1 " << ProgressionCounter << endl;
                while (DetermineDistance(Position1, String1, OldPosition1, OldString1) != true) {
                    ScalePosition1 = rand() % (counter);
                    String1 = rand() % 6;
                    Position1 = FindFretByNote(String1, ScalePosition1);
                }
                //cout << Position1 << " Position1 " << ScalePosition1 << " Scale Position" << endl;
                /*if ((rand() % 4) == 1) {
                    MultiNotes = true;
                    String2 = ReturnDifferentString(String1);
                    int* PossibleNotes = FindScaleOnString(String2);
                    ScalePosition2 = PossibleNotes[rand() % (int)(ScalePosition1 * sizeof(PossibleNotes))];
                } */
                for(int i = 0; i < 6; i++) {
                    Progression[i][ProgressionCounter] = '-';
                }
                ProgressionCounter++;
                char* temp1 = returnNumber(Position1);
                for(int i = 0; i < 6; i++) {
                    if (i == String1) {
                        Progression[i][ProgressionCounter] = temp1[0];
                        if (temp1[1] != 0) {
                            Progression[i][ProgressionCounter+1] = temp1[1];
                        }
                        //cout << Progression[i][ProgressionCounter] << " What we doin " << Position1 << endl;
                        OldPosition1 = Position1;
                        OldString1 = String1;
                    } else {
                        Progression[i][ProgressionCounter] = ' ';
                        if (temp1[1] != 0) {
                            Progression[i][ProgressionCounter+1] = ' ';
                        }
                    }
                }
                ProgressionCounter++;
                if (temp1[1] != 0) {
                    ProgressionCounter++;
                }
                for(int i = 0; i < 6; i++) {
                    Progression[i][ProgressionCounter] = '-';
                    Progression[i][ProgressionCounter+1] = '|';
                }
                ProgressionCounter += 2;
            }
            //cout << "Testing6" << endl;
            for(int i = 0; i < 6; i++) {
                for(int j = 0; j < 80; j++) {
                    cout << Progression[i][j];
                }
                cout << endl;
            }
        }

};


int main() {
    GuitarStuff g;
    string ModeType = "Dorian";
    int Shift = 3;
    char** Testing = new char*[2];
    Testing[0] = new char[2];
    Testing[0][0] = 's';
    Testing[0][1] = Shift;
    //cout << Testing[0][0] << Testing[0][1] << endl;
    g.PrintRandomProgression(ModeType, Shift);
    /*g.PrintMode(1, ModeType, Shift);
    g.PrintMode(2, ModeType, Shift);
    g.PrintMode(3, ModeType, Shift);
    g.PrintMode(4, ModeType, Shift);
    g.PrintMode(5, ModeType, Shift);
    g.PrintMode(6, ModeType, Shift);
    cout << endl;*/
}
