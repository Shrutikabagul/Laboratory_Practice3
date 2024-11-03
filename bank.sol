// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {
    address public owner;
    uint public balance;

    // Constructor: Set the owner as the person who deploys the contract
    constructor() {
        owner = msg.sender;
        balance = 0;
    }

    // Modifier to check if the sender is the owner
    modifier onlyOwner() {
        require(msg.sender == owner, "Only the owner can perform this action.");
        _;
    }

    // Deposit money to the bank account
    function deposit() public payable {
        require(msg.value > 0, "Deposit amount must be greater than zero.");
        balance += msg.value;
    }

    // Withdraw money from the bank account
    function withdraw(uint _amount) public onlyOwner {
        require(_amount <= balance, "Insufficient balance.");
        balance -= _amount;
        payable(msg.sender).transfer(_amount);
    }

    // Show the current balance
    function getBalance() public view returns (uint) {
        return balance;
    }
}
