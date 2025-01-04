#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    Bureaucrat president("President", 1);

    AForm *shrub = intern.makeForm("shrubbery creation", "Garden");
    AForm *robot = intern.makeForm("robotomy request", "Bender");
    AForm *pardon = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm *unknown = intern.makeForm("unknown form", "Nowhere");

    if (shrub) {
        president.signForm(*shrub);
        president.executeForm(*shrub);
        delete shrub;
    }

    if (robot) {
        president.signForm(*robot);
        president.executeForm(*robot);
        delete robot;
    }

    if (pardon) {
        president.signForm(*pardon);
        president.executeForm(*pardon);
        delete pardon;
    }
	(void)unknown;
    return 0;
}
