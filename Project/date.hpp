#pragma once

class Date {
private:
    int year_;
    int month_;
    int day_;
    friend class DateManager;
};
