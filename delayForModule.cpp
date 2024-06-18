#include <string>

bool clockTick(int clock, std::string clockSet) {
	if (clockSet[clock] == '1') {
		return true;
	}
	return false;
}

std::string updateDelayForTrace(std::string trace, bool isC, bool truncateTrace) {
	std::string new_trace = trace;
	int trace_length = new_trace.length();
	std::string truncate_trace = "";
	if (truncateTrace) {
		bool foundfirst = false;
		for (int i = 1; i < trace_length; i++) {
			if ((foundfirst == false) && (new_trace[i] != 'b')) {
				continue;
			}
			else {
				if (new_trace[i] == 'b') {
					foundfirst = true;
				}
			}
			truncate_trace = truncate_trace + new_trace[i];
		}
		return truncate_trace;
	}
	if (isC) {
		if (new_trace[0] == 'b') {
			new_trace = new_trace + 'c';
		}
	}
	else {
		if (new_trace[0] == 'x') {
			new_trace = 'b';
		}
		else {
			if (new_trace[trace_length - 1] != 'b') {
				new_trace = new_trace + 'b';
			}
		}
	}
	return new_trace;

}
