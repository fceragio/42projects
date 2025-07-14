/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:07:29 by federico          #+#    #+#             */
/*   Updated: 2025/07/13 17:50:51 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "minishell_prompt: "
# define BUFFER_LIMIT 1000000
# define YES 1
# define NO 0
# define PIPE 1
# define REDIRECT_OUTPUT 2
# define REDIRECT_INPUT 3
# define ASSIGNATION 4
# define COMMAND 5
# define FLAG 6
# define ARGUMENT 7
# define REDIRECTION_ARG 8
# define HEREDOC 9
# define MALLOC_ERR 1
# define CMD_ERR 2
# define FILE_ERR 3
# define DIR_ERR 4
# define SYS_ERR 5
# define SYNTAX_ERR 6
# define SUCCESS 0

extern volatile sig_atomic_t	g_sig;

typedef struct s_queue
{
	int				*pipe_mode;
	char			*content;
	struct s_queue	*next;
}				t_queue;

typedef struct s_list
{
	int				token_id;
	int				token_len;
	char			*content;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_rdr_queue
{
	int					type;
	char				*name;
	char				*rdr_arg;
	struct s_rdr_queue	*next;
}				t_rdr_queue;

typedef struct s_tree
{
	int				type;
	char			*name;
	char			**vars;
	char			**local_vars;
	char			*exec_path;
	char			**cmd_args;
	struct s_tree	*left_node;
	struct s_tree	*right_node;
	t_queue			*assignations;
	t_rdr_queue		*redirection_queue;
}				t_tree;

typedef struct s_program
{
	struct sigaction	*sa;
	char				**envs;
	char				**local_envs;
	int					exit_status;
	t_queue				*input_queue;
	t_list				*token_list;
	t_tree				*execution_tree;
}				t_program;

typedef struct s_path_indices
{
	int	i;
	int	j;
	int	k;
}	t_path_indices;

typedef struct s_assemble_indices
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	skip_len;
}	t_assemble_indices;

typedef struct s_token_info
{
	int	i;
	int	len;
}	t_token_info;

//utils
int				string_len(char *str);
int				strings_are_equal(char *str1, char *str2);
char			*str_copy(char *str);
char			*realloc_string(char *old, char *new_str);
char			*string_minus_beginning(char *original, int trim_start);

//main
void			shell_init(t_program *shell,
					int *argc, char **argv, char **envp);
char			*get_input(t_program *shell);
void			parsing_and_executing(char *input, t_program *shell);
void			shell_clean(t_program *shell);

//envs
char			**copy_envp(char **envp, t_program *shell);
void			alloc_and_copy_sngl_envs(char **result,
					char **envp, t_program *shell);
void			copy_sngl_env(char *result, char *envp);
int				count_envp(char **envp);
void			clean_envs(char **result);	
void			really_add_env(char *new_env,
					char ***envs, t_program *shell);
void			substitute_env(char *new_env, char ***envs);
int				find_env(char *to_find, char **pool);
void			add_env(char *new_env, char ***envs, t_program *shell);
char			*custom_get_env(char *target, char **pool);
char			*find_env_in_queue(char *to_find, t_queue *queue);
void			remove_env(char *target,
					char ***envs, t_program *shell);

//get_input
void			queue_init(t_queue **queue,
					char *line_read, t_program *shell);
int				invalid_pipe(char *line_read);
void			queue_append(t_queue **queue, t_program *shell);
t_queue			*queue_last(t_queue *queue);
void			queue_free(t_queue **queue);
void			queue_cat(t_queue *queue,
					char **target, int tot_len, t_program *shell);
int				queue_len(t_queue *queue);
void			queue_newline(t_queue **queue, t_program *shell);
int				input_is_complete(t_queue *queue);
void			wait_next_target(t_queue **queue,
					int *i, char target, int *flag);
void			wait_valid_char(t_queue **queue, int *i, int *flag);
void			list_add(t_list **list, char *str,
					t_token_info *info, t_program *shell);

void			list_add_nl_after_redirect(t_list **token_list,
					t_program *shell);
void			list_append(t_list **list,
					t_list *new_node, char *token);
t_list			*list_last(t_list *list);
void			list_reset(t_list **list);

//tokenize
t_list			*tokenize(char *input, t_program *shell);
void			trim_forespace(char	*str, int *i, t_list *list);
int				list_check_redirect(t_list *list);
int				measure_token(char *str, int i);
void			measure_dblquotes(char *str, int i, int *len);
void			measure_snglquotes(char *str, int i, int *len);
void			measure_major(char *str, int i, int *len);
void			measure_minor(char *str, int i, int *len);
int				measure_redirect(char *str, int i);
int				identify_pipes(t_list **token_list);
int				identify_redirections(t_list **token_list);
void			identify_assignations(t_list **token_list);
void			find_and_translate_envs(t_list **token_list,
					t_program *shell);
char			*find_env_value(char *name, t_program *shell);
void			assemble_new_str(char *new_s, char *to_insert,
					char *old, t_assemble_indices *idx);

void			skip_envs_inside_snglquotes(char *str,
					int *i, t_program *shell);
void			translate_env(t_list *temp, int i, t_program *shell);
void			token_substitute_env(char *env,
					t_list **temp, int i, t_program *shell);
void			token_substitute_with_last_exit_code(char *env,
					t_list **temp, int i, t_program *shell);
char			*int_to_str(int x, t_program *shell);

void			translate_envs_inside_dblquotes(t_list *temp,
					int *i, t_program *shell);
void			remove_quotes(t_list **token_list, t_program *shell);
void			skip_dblquotes(int *i, int *new_len,
					char *old_content, char *clean_buffer);
void			skip_snglquotes(int *i, int *new_len,
					char *old_content, char *clean_buffer);
void			reset_buffer(char *clean_buffer, int i);
void			realloc_token_content(t_list *token_node,
					char *clean_buffer, int len, t_program *shell);
void			identify_commands(t_list **token_list);

//parsing
t_tree			*parsing(t_list *token_list, t_program *shell);
t_tree			*create_tree(t_list **token_list, t_program *shell);
t_tree			*create_tree_node(t_list *token_list, t_program *shell);
t_tree			*tree_create_pipe_node(t_list *token_list, t_program *shell);
t_list			*list_find_next_command(t_list *token_list);
t_tree			*tree_create_command_node(t_list *token_list, t_program *shell);
char			**set_command_local_vars(t_program *shell,
					t_queue *command_assignations);
char			**set_command_vars(t_program *shell,
					t_queue *command_assignations);
char			*set_command_exec_path(char *name,
					char **command_env, t_program *shell);
t_queue			*set_command_assignations(t_list *token_list, t_program *shell);
t_queue			*create_assignation_queue(t_list *token_list, t_program *shell);
void			queue_append_assignation(t_queue **queue,
					char *assignation, t_program *shell);
t_list			*find_first_assignation(t_list *token_list);
char			*find_executable(char *name,
					char **command_env, t_program *shell);
char			**get_path_dirs(char **command_env, t_program *shell);
int				dir_qnt(char *path);
void			split_path_dirs(char ***path_dirs,
					char *path, int qnt, t_program *shell);
void			clean_path_dirs(char **path_dirs);
int				dir_len(char *path);
void			set_executable(char **executable, char *path, char *name);
char			**set_command_args(t_list *token_list, t_program *shell);
int				count_args(t_list *token_list);
t_rdr_queue		*set_redirection_queue(t_list *token_list, t_program *shell);
void			append_rdr_queue(t_rdr_queue **head,
					t_list *token_list, t_program *shell);
t_rdr_queue		*last_rdr(t_rdr_queue *head);
void			tree_free_node(t_tree **node);
void			tree_free_command(t_tree *node);
void			free_rdr(t_rdr_queue *head);
void			tree_free_pipe(t_tree *node);
int				assign_token_id(t_list **token_list, t_program *shell);
void			adjust_token(t_list	**token_list, t_program *shell);
t_list			*list_insertion_point(t_list *temp);
int				no_command_in_block(t_list *temp);
t_list			*list_surpass_next_pipe(t_list *temp);
void			list_insert_fake_command(t_list **token_list, t_program *shell);
void			list_insert_right(t_list *new_node, t_list **token_list);
void			list_insert_left(t_list *new_node, t_list **token_list);

//executing
void			execute_tree(t_tree *root, t_program *shell);
void			change_shell_envs(t_tree *tree, t_program *shell);
int				tree_only_assignations(t_tree *tree);
void			exec_node(t_tree *node, t_program *shell);
void			exec_pipe(t_tree *node, t_program *shell);
void			exec_pipe_left(t_tree *node,
					int *pipe_fds, pid_t *pid1, t_program *shell);
void			exec_pipe_right(t_tree *node,
					int *pipe_fds, pid_t *pid2, t_program *shell);
void			exec_command(t_tree *node, t_program *shell);
void			exec_executable(t_tree *node, t_program *shell);
void			exec_builtin(t_tree *node, t_program *shell);

void			exec_exit(t_tree *node, t_program *shell);
void			exit_with_status(char *status, t_program *shell);
unsigned char	convert_status(char *status);
int				non_numeric(char *str);
void			set_shell_exit_status(int status, t_program *shell);

void			exec_echo(t_tree *node, t_program *shell);

void			exec_export(t_tree *node, t_program *shell);
int				contains_equal(char	*arg);
int				valid_identifier(char *arg);
void			export_by_name(char *arg, t_queue *assignations,
					t_program *shell);
void			export_expression(char *arg, t_program *shell);
void			export_raw(char **envs, t_program *shell);
t_queue			*sort_envs(char **envs, t_program *shell);
int				higher(char *str1, char *str2);
void			append_in_order(char *content,
					t_queue **queue, t_program *shell);
void			print_all_export_format(t_queue *sorted_envs);
void			print_env_value(char *env);
void			print_env_identifier(char *env);
void			exec_unset(t_tree *node, t_program *shell);
void			try_to_remove(char *target, char ***envs,
					char ***local_envs, t_program *shell);
void			exec_env(t_tree *node, t_program *shell);
void			print_string_array(char **strings);
void			exec_cd(t_tree *node, t_program *shell);
void			cd_home(t_tree *node, t_program *shell);
void			exec_pwd(t_tree *node, t_program *shell);
int				spare_streams_init(int *spare_stdout,
					int *spare_stdin, t_program *shell);
int				restore_streams(int spare_stdout,
					int spare_stdin, t_program *shell);
int				resolve_redirections(t_tree *node, t_program *shell);
int				resolve_redirect_output(t_rdr_queue *temp, t_program *shell);
int				resolve_write_output(t_rdr_queue *temp, t_program *shell);
int				resolve_append_output(t_rdr_queue *temp, t_program *shell);
int				resolve_redirect_input(t_rdr_queue *temp, t_program *shell);
int				resolve_read_input(t_rdr_queue *temp, t_program *shell);
int				resolve_heredoc(t_rdr_queue *temp, t_program *shell);

//heredoc
void			find_and_substitute_heredocs(t_list **token_list,
					t_program *shell);
void			get_and_substitute_heredoc(t_list *heredoc,
					t_program *shell);
t_queue			*new_reads_init(t_program *shell);
void			new_reads_append_newline(t_queue *new_reads, t_program *shell);
void			new_reads_append_newnode(t_queue *new_reads, t_program *shell);
int				found_heredoc_target(t_queue *new_reads,
					char *target, t_program *shell);
void			clean_heredoc_queue(t_queue *new_reads);
void			cat_and_substitute_heredoc(t_queue *new_reads,
					char **target, t_program *shell);
int				heredoc_len(t_queue *new_reads, char *target);
void			copy_new_heredoc(t_queue *new_reads,
					int len, char *new_content);
void			translate_heredoc_envs(t_list *temp, t_program *shell);
void			copy_till_begin_of_target(char *new_content,
					char *to_trim, int len);
int				len_till_target(char *str, char *target);
void			trim_after_target(t_queue *temp,
					char *target, t_program *shell);

//signals
void			sig_handler(int s_num);
void			sig_init(struct sigaction *sa);
void			temp_sig_init(struct sigaction *sa, struct sigaction *old);
void			temp_sig_handler(int s_num);
void			restore_sigaction(struct sigaction *old);

//errors
void			print_error(char *error);
void			manage_error(int er_type, char *error, t_program *shell);
void			manage_critical_error(int er_type,
					char *error, t_program *shell);

#endif