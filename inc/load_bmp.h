/*
** load_bmp.h for  in /home/debrau_c/COURS/InfoG/LibLapin/Fil_De_Fer2/gfx_wolf3d
** 
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Dec 25 03:51:23 2015 Carl DEBRAUWERE
** Last update Sun Apr 17 18:06:09 2016 debrau_c
*/

#ifndef LOAD_BMP_H
# define LOAD_BMP_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "lapin.h"

typedef struct			s_file
{
  char				sign[2];
  int				size;
  int				rsv;
  int				offset;

  int				size_hdr;
  int				w_bmp;
  int				h_bmp;
  short				nb_plan;
  short				bpp;
  int				compr;
  int				size_img;
  int				reso_hori;
  int				reso_vert;
  int				nb_pal;
  int				nb_paluse;
}__attribute__((packed)) t_file;

t_bunny_pixelarray	*cut_bmp(t_bunny_pixelarray *pix,
				 int width,
				 int height);
t_bunny_pixelarray	*load_bmp(char *pathname);

#endif /* LOAD_BMP_H */
