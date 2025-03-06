#include <windows.h>

int main(void)
{
	const char* custom_log_name = "213021363";
	// create registry keys for ACLing described on MSDN: http://msdn2.microsoft.com/en-us/library/aa363648.aspx
	HANDLE event_log = RegisterEventSource(NULL, custom_log_name);
	const char* message = "I'm in an event log";
	ReportEvent(event_log, EVENTLOG_SUCCESS, 0, 0, NULL, 1, 0, &message, NULL);
	
	return 0;
}

