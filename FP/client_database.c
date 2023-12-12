#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
void createUser(const char* username, const char* password) {
    if (geteuid() != 0) {
        printf("This function can only be executed with sudo privileges.\n");
        return;
    }
    FILE *file = fopen("users.txt", "a");
    fprintf(file, "%s:%s\n", username, password);
    fclose(file);
    printf("User created successfully!\n");
}

void createDatabase(const char* databaseName) {
    char* databasesPath = "./database/";
    char* databasePath = malloc(strlen(databasesPath) + strlen(databaseName) + 1);
    strcpy(databasePath, databasesPath);
    strcat(databasePath, databaseName);

    if (!access(databasePath, F_OK)) {
        printf("database already exists.\n");
    } else {
        if (!mkdir(databasePath, 0777)) {

            printf("database created successfully!\n");
        } else {
            printf("Failed to create database.\n");
        }
    }

    free(databasePath);
}

void useDatabase(const char* databaseName) {
    char* databasesPath = "./database/";
    char* databasePath = malloc(strlen(databasesPath) + strlen(databaseName) + 1);
    strcpy(databasePath, databasesPath);
    strcat(databasePath, databaseName);

    if (!access(databasePath, F_OK)) {
        printf("database exists.\n");
    } else {
        printf("database doesn't exist.\n");
    }

    free(databasePath);
}

void grantPermissiontoaccessDatabase(const char* username, const char* databaseName) {
    if (geteuid() != 0) {
        printf("This function can only be executed with sudo privileges.\n");
        return;
    }
    char* databasesPath = "./database/";
    char* databasePath = malloc(strlen(databasesPath) + strlen(databaseName) + 1);
    strcpy(databasePath, databasesPath);
    strcat(databasePath, databaseName);

    if (!access(databasePath, F_OK)) {
        FILE *file = fopen("user.txt", "a");
        fprintf(file, "%s:%s\n", username, databaseName);
        fclose(file);
        printf("Permission granted successfully!\n");
    } else {
        printf("database doesn't exist.\n");
    }

    free(databasePath);
}

void createTable(const char* databaseName, const char* tableName, char* columns[]) {
    char* databasesPath = "./database/";
    char* databasePath = malloc(strlen(databasesPath) + strlen(databaseName) + 1);
    strcpy(databasePath, databasesPath);
    strcat(databasePath, databaseName);

    if (!access(databasePath, F_OK)) {
        char* tablePath = malloc(strlen(databasePath) + strlen(tableName) + 2);
        strcpy(tablePath, databasePath);
        strcat(tablePath, "/");
        strcat(tablePath, tableName);

        FILE *file = fopen(tablePath, "w");
        for (int i = 0; columns[i] != NULL; i++) {
            fprintf(file, "%s\n", columns[i]);
        }
        fclose(file);
        printf("Table created successfully!\n");
    } else {
        printf("Database doesn't exist.\n");
    }

    free(databasePath);
}

void logCommand(const char* username, const char* command) {
    FILE *file = fopen("log.txt", "a");
    if (file == NULL) {
        printf("Failed to open log file.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(file, "%04d-%02d-%02d %02d:%02d:%02d:%s:%s\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
            tm.tm_hour, tm.tm_min, tm.tm_sec, 
            username, command);

    fclose(file);
}
