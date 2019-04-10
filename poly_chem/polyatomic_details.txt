polyatomic.h  // Header file.
polyatomic.cpp // Implementation file,
poly_main.cpp // Testing.

START: 2/28/18
END: ...



A small polyatomic ion review program.
Takes an arbitrary polyatomic ion from a defined list. User will be given a compound OR a compound name.
Based off of that, the user will be asked to identify the correct charge, compound/compound name ... OR ALL.

Score Tracking : keeps track of correct answers.
Current Streak : number of correct questions answered consecutively.
Mastery: highest streak by user ... returns a ratio of max streak/total polyatomic ions.
Specific Information: User can be asked for a charge, polyatomic name, or molecular formula.

There set and get functions for each.
One of the first OOP small project for practice. Frankly, it's taking more longer than it should.


UPDATE: 4/5/19 
-- DOES COMPILE AND RUN.
-- ADDED MACRO GAURD IN CPP FILE.
-- Most have worked in poly_main.cpp, but needs further testing.

	added FUNCTIONS:
	void setPoly(const size_t& newPoly); 	-- Renamed from getPoly.
	void setSection(const size_t& section); -- Sets selection for the correct answer ... meaning the correct charge, compound or compound name.
	void askPrint()const;			-- Specifically asks what the current selection is needed ... meaning the correct charge, compound or compound name.
	string correctAns() const; 		-- Display the absoulute correct answer ... meaning the correct charge, compound or compound name.
	void printAns() const; 			-- Used to print the correct polyatomic ion for printing.  (WIP)
	
	added Private VARIABLE:
	size_t currentSection; 			-- Keeps track of what information is needed ... it is the #of the array in polyData ... meaning the correct charge, compound or compound name.

	updated FUNCTION:
	void checkAns(const string& ans) const; -- Now fully prints wether the given answer is correct or incorrect.
	void scoreUpdate(const bool& correct);	-- Fully functional and updates score on whether or not user was correct.
	size_t getSectionVal() const; // returns array value containing charge, compounds, or compound name 	-- Gets the value of the current section of the current polyatomic ion.
	size_t getPolyVal() const;    // returns array for specific polyatomic ion				-- Gets the Value of the Specific polyatomic ion.
	
**Will add 3 strikes you're out.
**Will add correction when you have to be asked a compound formula then we display compound name and vice versa.
**Maybe include random generator in implementation file ... not sure yet.
**Fix printAns function that  DOESNT PRINT SO NICE ACTUALLY ....
