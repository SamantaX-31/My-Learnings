#include <stdio.h>
#include <string.h>

// Function to check if a name exists in a given list of names
int isNamePresent(char *name_list[], int size, const char *target_name) {
    // A simple linear search is used here for comparison.
    // For large lists, a sorted list with binary search would be more efficient.
    for (int i = 0; i < size; i++) {
        // Use strcmp to compare the strings
        if (strcmp(name_list[i], target_name) == 0) {
            return 1; // Name found
        }
    }
    return 0; // Name not found
}

int main() {
    // List of student names from the attendance report (as a constant array)
    char *attendance_report_names[] = {
        "AATREYEE CHATTERJEE", "ABHIJEET KUMAR JHA", "ADITYA KUMAR", "AMAR KUMAR",
        "ANKIT KUMAR", "ANKITA DATTA", "ANKUSH BURMAN", "ANSHU CHOURASIA",
        "ARCHITA MANDAL", "ARGHYA PAL", "ARNAB HALDER", "ARNAB MAITY",
        "ARPITA PRAHARAJ (T)", "ARPITA ROY", "ARJUN SINGH", "ASIFUR RAHAMAN",
        "BAISHALI SAMADDER", "DEBANGAN DASGUPTA", "FURQUANA JEELANI", "GEETIKA ROY",
        "HIMANSHU KUMAR", "INDRANIL PANDA", "JYOTI KUMARI SHAW", "KARAN PRASAD",
        "KOUSHIK DAS", "MUNSHI YASIR RAHMAN", "NILANJAN SAHA", "POULAMI ROY",
        "PRAJUKTA MUKHERJEE", "PRANIT BHOWMICK", "PRIYANGSHU BARIK", "PRIYOJIT POREL",
        "PRITAM SAHA", "PURNIMA SINGH", "RAHUL DEY", "RAHUL THAKUR",
        "RINI ROY", "ROKI MONDAL", "RONI ROY", "SAHIL KUMAR", "SAMRAT NASKAR",
        "SAMRIDHA BANERJEE", "SAMRIDHYA DASGUPTA", "SANTANU GHOSH", "SAYAK CHANDRA",
        "SAYAK PRATIHAR", "SAYAN POULIEK", "SAYANDEEP CHATTERJEE", "SAYANI BHATTACHARYA",
        "SHREYA YADAV", "SHROBONA MUKHERJEE", "SHUBHANGINI BHATTACHAR", "SHUVAJIT SAMANTA",
        "SIDDHARTH CHOWDHURY", "SOHAM SAMANTA", "SOMU CHOWDHURY(T)", "SOURASHISH PAL",
        "SOUMYADIP SETH", "SRIJAN DAS", "SRISHTI SINGH", "SUGATA NATH", "SUJAL HALDER",
        "SOUDAS NASKAR", "SWASTIK SADHU", "TANISHA DAS", "TITHI GHOSH(T)",
        "TIYASHA DEB", "TUHIN SUBHRA GHORAI", "UTSA PAUL", "HARSH KUMAR"
    };

    // Names extracted from the screenshots you provided.
    char *drive_names[] = {
        "UTSA PAUL", "TUHIN SUBHRA GHORAI", "TIYASHA DEB", "TITHI GHOSH",
        "TANISHA DAS", "SWASTIK SADHU", "SUJAL HALDER", "SUGATA NATH",
        "SRISHTI SINGH", "SRIJAN DAS", "SOURASHISH PAL", "SOUMYADIP SETH",
        "SOUDAS NASKAR", "SOMU CHOWDHURY", "SOHAM SAMANTA", "SIDDHARTH CHOWDHURY",
        "SHUVAJIT SAMANTA", "SHUBHANGINI BHATTACHAR", "SHROBONA MUKHERJEE",
        "SHREYA YADAV", "SAYANI BHATTACHARYA", "SAYANDEEP CHATTERJEE",
        "SAYAK PRATIHAR", "SAYAK CHANDRA", "SANTANU GHOSH", "SAMRIDHYA DASGUPTA",
        "SAMRIDHA BANERJEE", "SAMRAT NASKAR", "RONI ROY", "ROKI MONDAL",
        "RINI ROY", "RAHUL THAKUR", "RAHUL DEY", "PURNIMA SINGH",
        "PRIYOJIT POREL", "PRIYANGSHU BARIK", "PRITAM SAHA", "PRANIT BHOWMICK",
        "PRAJUKTA MUKHERJEE", "POULAMI ROY", "NILANJAN SAHA", "MUNSHI YASIR RAHMAN",
        "KOUSHIK DAS", "JYOTI KUMARI SHAW", "INDRANIL PANDA", "HIMANSHU KUMAR",
        "HARSH KUMAR", "FURQUANA JEELANI", "DEBANGAN DASGUPTA", "BAISHALI SAMADDER",
        "ASIFUR RAHAMAN", "ARPITA ROY", "ARPITA PRAHARAJ (T)", "ARNAB MAITY",
        "ARNAB HALDER", "ARJUN SINGH", "ARGHYA PAL", "ARCHITA MANDAL",
        "ANSHU CHOURASIA", "ANKUSH BURMAN", "ANKITA DATTA", "ANKIT KUMAR",
        "AMAR KUMAR", "ADITYA KUMAR", "ABHIJEET KUMAR JHA", "AATREYEE CHATTERJEE"
    };
    
    // Calculate the size of each list
    int attendance_size = sizeof(attendance_report_names) / sizeof(attendance_report_names[0]);
    int drive_size = sizeof(drive_names) / sizeof(drive_names[0]);

    printf("Names present in the attendance report but not in the Google Drive folder:\n");
    printf("----------------------------------------------------------------------\n");

    // Loop through the attendance report names
    for (int i = 0; i < attendance_size; i++) {
        // Check if the name from the report is NOT present in the drive names list
        if (!isNamePresent(drive_names, drive_size, attendance_report_names[i])) {
            printf("%s\n", attendance_report_names[i]);
        }
    }

    return 0;
}
