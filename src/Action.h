#pragma once

enum class ActionType {
  CHECK,
  CALL,
  RAISE,
  FOLD  
};

struct Action {
    ActionType actionType;
    int amount;
};