#pragma once

#ifdef _cplusplus
extern "C"
{
#endif

	//����������
	int ReadcgdFile(char *file, char *key, char *value, int *len);
	int WritecgdFile(char *file, char *key, char *value, int len);


#ifdef _cplusplus
}
#endif