// 
// 234218 Data Structures 1.
// Semester: 2024B (spring).
// Wet Exercise #2.
// 
// Recommended TAB size to view this file: 8.
// 
// The following header file contains necessary types for your code.
// This file is READ ONLY: even if you submit something else, the compiler ..
// .. WILL use our file.
// 
// DO NOT use the preprocessors in your own code files.
// 

#ifndef WET2_UTIL_H_
#define WET2_UTIL_H_

#include <stdexcept>

// StatusType
enum struct StatusType {
	SUCCESS          = 0,
	ALLOCATION_ERROR = 1,
	INVALID_INPUT    = 2,
	FAILURE          = 3,
};

// output_t<T>
// The following class is used to support output with status code.
template<typename T>
class output_t {
private:
	// DO NOT access these private fields - may be enforced by verifier.
	const StatusType __status;
	const T __ans;

public:
	output_t() : __status(StatusType::SUCCESS), __ans(T()) { }
	output_t(StatusType status) : __status(status), __ans(T()) { }
	output_t(const T &ans) : __status(StatusType::SUCCESS), __ans(ans) { }
	
	StatusType status() const { return __status; }
	T ans() { return __ans; }
};


#endif // WET2_UTIL_H_
