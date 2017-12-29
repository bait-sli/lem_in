#include "lem_in.h"

static int check_call(char *current, t_pipe **network)
{
  t_pipe *elem;

  elem = *network;
  while(elem != NULL)
  {
    if((ft_strcmp(current, elem->room1) == 0 || ft_strcmp(current, elem->room2) == 0) && elem->call == 0)
      return(1);
    elem = elem->next;
  }
  return(0);
}

static char *ft_find(char *step, char *room1, char *room2)
{
  char *ret;

  if(ft_strcmp(step, room1) == 0)
    ret = ft_strdup(room2);
  if(ft_strcmp(step, room1) == 0)
    ret = ft_strdup(room2);
  return(ret);
}

static void ft_build_path(char *end, t_env *env, t_pipe **network)
{
  t_pipe *elem;
  char *tmp2;
  t_path *path;

  path = env->path;
  elem = *network;
  while(elem != NULL)
  {
    if((ft_strcmp(path->step, elem->room1) == 0 || ft_strcmp(path->step, elem->room2) == 0) && elem->call == 0)
    {
      elem->call = 1;
      tmp2 = ft_find(path->step, elem->room1, elem->room2);
      if(ft_strcmp(end, tmp2) == 0)
      {
        add_to_path(tmp2, &env->path);
        break ;
      }
      if(ft_strcmp(end, tmp2) != 0)
      {
        add_to_path(tmp2, &env->path);
        ft_build_path(end, env, network);
      }
      break ;
    }
    if((ft_strcmp(path->step, elem->room1) == 0 || ft_strcmp(path->step, elem->room2) == 0) && elem->call == 1)
    {
      tmp2 = ft_find(path->step, elem->room1, elem->room2);
      if(ft_strcmp(end, tmp2) == 0)
      {
        add_to_path(tmp2, &env->path);
        break ;
      }
      if(check_call(tmp2, network) == 1)
      {
        add_to_path(tmp2, &env->path);
        ft_build_path(end, env, network);
      }
      if(check_call(tmp2, network) == 0)
      {
        delete_one(&env->path);
        elem->call = 2;
        ft_build_path(end, env, network);
      }
      break ;
    }
    elem = elem->next;
  }
}

static char *get_start_end(t_vertice **map, int usage)
{
  char *ret;
  t_vertice *elem;

  elem = *map;
  while(elem != NULL)
  {
    if(elem->usage == usage)
      return(ft_strdup(elem->name));
    elem = elem->next;
  }
  return(NULL);
}

void ft_resolve(t_env *env)
{
  char *start;
  char *end;

  start = get_start_end(&env->map, 1);
  end = get_start_end(&env->map, 2);
  add_to_path(start, &env->path);
  ft_build_path(end, env, &env->network);
}
