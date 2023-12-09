
#pragma once

/**
 * @brief This function is meant to be called before main and init some data 
 * 
 */
void construct() __attribute__((constructor));

/**
 * @brief This function is meant to be called after main and destroy some data
 * 
 */
void destruct() __attribute__((destructor));
