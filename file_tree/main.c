#include <stdlib.h>
#include <stdio.h>

int parsing(char *path) {
	char *Path = path;
	for(; *Path != '\0' && *Path != '\\'; Path++);
	if(*Path != '\0') {
		*Path = '\0';
		Path++;
		parsing(Path);
	}
	printf("%s\n", path);
	return 0;
}

int main() {
	char path[1024];
	scanf("%s", path);
	parsing(path);
	return 0;
}
