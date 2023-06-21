#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void execute(char *argv)
{
	        int ln = 0, r = 0;
		        char *token = NULL, *temp = NULL;
			        stack_t *stack = NULL;

				        FILE *file = fopen(argv, "r");
					        if (file)
							        {
									                char line[MAX_LINE_LENGTH];
											                while (fgets(line, sizeof(line), file) != NULL)
														                {
																	                        ln++;
																				                        token = strtok(line, " \n\t\r");
																							                        if (token == NULL)
																											                        {
																															                                continue;
																																			                        }
																										                        else if (*token == '#')
																														                                continue;
																													                        temp = strtok(NULL, " \n\t\r");
																																                        r = get_operation(&stack, token, temp, ln);
																																			                        if (r == 1) /* get_opt returns 1 when the value is not a digit */
																																							                                pushing_error(file, line, stack, ln); /** print push error */
																																						                        else if (r == -1) /* get_opt returns -1 if not the instruction */
																																										                                instruction_error(file, line, stack, token, ln);
																																									                                        /* print instruction error */
																																									                }
													                fclose(file);
															        }
						        else
								        {
										                open_error(argv);
												        }
}

