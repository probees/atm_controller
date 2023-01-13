# ATM Controller (Design)
- API
  - create_controller(Model*) : instance
  - instance destroy_controller() : instance
  - insert_card(Card*) : int
  - check_PIN(...) : int
  - select_account(...) : int
  - get_balance(BalanceReport*) : int
  - get_deposit(Deposit*) : int
  - get_withdraw(Withdraw*) : int
- Model
  - ModelProxy 
  - ModelRemote : Production-Mode
  - ModelLocal  : ONLY for Debugging (you can do on local database)



# Dev. Env.
- macosx
  - brew install xmake

# How to Compile
```shell
    xmake build atm_controller
```

# How to Test
```shell
    xmake run api_test
```
