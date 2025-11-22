#ifndef COMMAND_H
#define COMMAND_H

#include "inventory.h"
class Command
{
public:
    Command(Inventory& inventory, std::vector<std::string> args): inventory(inventory), args(args) {};
    virtual ~Command() {};

    virtual void execute() const = 0;
protected:
    Inventory& inventory;
    std::vector<std::string> args;
};

class AddCommand : public Command {
public:
    using Command::Command;
    void execute() const override;
};

class RemoveCommand : public Command {
public:
    using Command::Command;
    void execute() const override;
};

class UpdateCommand : public Command {
public:
    using Command::Command;
    void execute() const override;
};

class DisplayCommand : public Command {
public:
    using Command::Command;
    void execute() const override;
};

class ReadCommand : public Command {
public:
    using Command::Command;
    void execute() const override;
};

class SaveCommand : public Command {
public:
    using Command::Command;
    void execute() const override;
};

class HighestCommand : public Command {
public:
    using Command::Command;
    void execute() const override;
};

class BelowCommand : public Command {
public:
    using Command::Command;
    void execute() const override;
};


#endif // COMMAND_H
