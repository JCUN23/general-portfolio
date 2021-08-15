#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#include <dirent.h>
#include <sys/types.h>

string proteinTranslator(char block, string filename) {
    ifstream protein(filename);
    string line;
    string proteinChain;

    while(getline(protein, line))
 {
     string type = "ATOM  ";
     string aminoAcid;
     string aminoAcidChain;
         char aminoAcid1 = line[17];
         char aminoAcid2 = line[18];
         char aminoAcid3 = line[19];
         aminoAcid += aminoAcid1;
         aminoAcid += aminoAcid2;
         aminoAcid += aminoAcid3;
         
     if (line.find(type) != std::string::npos && line[21] == block) //If the current line contains an amino acid we want to print...
     {
         //Break down list by block
         //print out the amino acid from that line
         aminoAcidChain += aminoAcid;
         aminoAcidChain += " ";
     }
     proteinChain += aminoAcidChain;
 }

protein.close();
return proteinChain;
}

string proteinAbbrTranslator(char block, string filename){
 string aminoAcidChain = "";
 ifstream protein(filename);
 string line2;
 while(getline(protein,line2))
 {
     // Create Second, Abbreviated Chain
     string type2 = "ATOM  ";
        char aminoAcid4 = line2[17];
        char aminoAcid5 = line2[18];
        char aminoAcid6 = line2[19];
     //Replace all the current amino acids with their abbreviations and print them

     if (line2.find(type2) != std::string::npos && line2[21] == block) //If the current line contains an amino acid we want to print...
     {
        if ((aminoAcid4 == 'A') && (aminoAcid5 == 'L') && (aminoAcid6 == 'A'))
        {
            aminoAcidChain += "A";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'A') && (aminoAcid5 == 'R') && (aminoAcid6 == 'G'))
        {
            aminoAcidChain += "R";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'A') && (aminoAcid5 == 'S') && (aminoAcid6 == 'N'))
        {
            aminoAcidChain += "N";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'A') && (aminoAcid5 == 'S') && (aminoAcid6 == 'P'))
        {
            aminoAcidChain += "D";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'C') && (aminoAcid5 == 'Y') && (aminoAcid6 == 'S'))
        {
            aminoAcidChain += "C";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'G') && (aminoAcid5 == 'L') && (aminoAcid6 == 'N'))
        {
             aminoAcidChain += "Q";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'G') && (aminoAcid5 == 'L') && (aminoAcid6 == 'U'))
        {
            aminoAcidChain += "E";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'G') && (aminoAcid5 == 'L') && (aminoAcid6 == 'Y'))
        {
             aminoAcidChain += "G";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'H') && (aminoAcid5 == 'I') && (aminoAcid6 == 'S'))
        {
            aminoAcidChain += "H";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'I') && (aminoAcid5 == 'L') && (aminoAcid6 == 'E'))
        {
            aminoAcidChain += "I";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'L') && (aminoAcid5 == 'E') && (aminoAcid6 == 'U'))
        {
            aminoAcidChain += "L";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'L') && (aminoAcid5 == 'Y') && (aminoAcid6 == 'S'))
        {
           aminoAcidChain += "K";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'M') && (aminoAcid5 == 'E') && (aminoAcid6 == 'T'))
        {
            aminoAcidChain += "M";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'P') && (aminoAcid5 == 'H') && (aminoAcid6 == 'E'))
        {
            aminoAcidChain += "F";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'P') && (aminoAcid5 == 'R') && (aminoAcid6 == 'O'))
        {
            aminoAcidChain += "P";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'P') && (aminoAcid5 == 'Y') && (aminoAcid6 == 'L'))
        {
            aminoAcidChain += "O";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'S') && (aminoAcid5 == 'E') && (aminoAcid6 == 'R'))
        {
            aminoAcidChain += "S";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'S') && (aminoAcid5 == 'E') && (aminoAcid6 == 'C'))
        {
            aminoAcidChain += "U";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'T') && (aminoAcid5 == 'H') && (aminoAcid6 == 'R'))
        {
            aminoAcidChain += "T";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'T') && (aminoAcid5 == 'R') && (aminoAcid6 == 'P'))
        {
            aminoAcidChain += "W";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'T') && (aminoAcid5 == 'Y') && (aminoAcid6 == 'R'))
        {
            aminoAcidChain += "Y";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'V') && (aminoAcid5 == 'A') && (aminoAcid6 == 'L'))
        {
             aminoAcidChain += "V";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'A') && (aminoAcid5 == 'S') && (aminoAcid6 == 'X'))
        {
            aminoAcidChain += "B";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'G') && (aminoAcid5 == 'L') && (aminoAcid6 == 'X'))
        {
            aminoAcidChain += "Z";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'Z') && (aminoAcid5 == 'A') && (aminoAcid6 == 'A'))
        {
            aminoAcidChain += "X";
            aminoAcidChain += " ";
        }
        else if ((aminoAcid4 == 'X') && (aminoAcid5 == 'L') && (aminoAcid6 == 'E'))
        {
           aminoAcidChain += "J";
            aminoAcidChain += " ";
        }
        else {
            return "Amino Acid not found. ";
        }
     }
 }
 protein.close();
 return aminoAcidChain;
}

int main() 
{
    ifstream dataBaseList;
    dataBaseList.open("databaselist.txt");
    if (!(dataBaseList.is_open()))
    {
        cout << "Error opening file." << endl;
    }
    string proteinFileName;
    while(dataBaseList >> proteinFileName) {
         //Original Chain, Create chains for each block and print them to the respective protein's file
        ofstream dataBaseTranslate(proteinFileName + ".txt");
         dataBaseTranslate << "Block A:" << endl;
         string blockA = proteinTranslator('A', proteinFileName);
         dataBaseTranslate << blockA << endl;
         dataBaseTranslate << "Block B: " << endl;
         string blockB = proteinTranslator('B', proteinFileName);
         dataBaseTranslate << blockB << endl;
         dataBaseTranslate << "Block C: " << endl;
         string blockC = proteinTranslator('C', proteinFileName);
         dataBaseTranslate << blockC << endl;
         dataBaseTranslate << "Block D:" << endl;
         string blockD = proteinTranslator('D', proteinFileName);
         dataBaseTranslate << blockD << endl;
         dataBaseTranslate << endl;
         //Abbreviated Chain, do the same thing as before
         dataBaseTranslate << "Block A:" << endl;
         string blockA_1 = proteinAbbrTranslator('A', proteinFileName);
         dataBaseTranslate << blockA_1 << endl;
         dataBaseTranslate << "Block B: " << endl;
         string blockB_1 = proteinAbbrTranslator('B', proteinFileName);
         dataBaseTranslate << blockB_1 << endl;
         dataBaseTranslate << "Block C: " << endl;
         string blockC_1 = proteinAbbrTranslator('C', proteinFileName);
         dataBaseTranslate << blockC_1 << endl;
         dataBaseTranslate << "Block D:" << endl;
         string blockD_1 = proteinAbbrTranslator('D', proteinFileName);
         dataBaseTranslate << blockD_1 << endl;
         dataBaseTranslate << endl;
         dataBaseTranslate << endl;
    }
}
