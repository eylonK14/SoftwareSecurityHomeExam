#include <windows.h>

int main(void)
{
	const char *message = "213021363";
	ReportEventA(RegisterEventSourceA(NULL, message), EVENTLOG_SUCCESS, 0, 0, NULL, 1, 0, &message, NULL);
	return 0;
}
