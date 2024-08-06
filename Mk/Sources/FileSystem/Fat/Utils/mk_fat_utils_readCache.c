/**
*
* @copyright Copyright (C) 2021 RENARD Mathieu. All rights reserved.
*
* This file is part of Mk.
*
* Mk is free software. Redistribution and use in source and binary forms, with or
* without modification, are permitted provided that the following conditions are
* met:
*
*    1. Redistributions of source code must retain the above copyright notice,
*       this list of conditions and the following disclaimer.
*    2. Redistributions in binary form must reproduce the above copyright notice,
*       this list of conditions and the following disclaimer in the documentation
*       and/or other materials provided with the distribution.
*    3. Neither the name of the copyright holder nor the names of its contributors
*       may be used to endorse or promote products derived from this software
*       without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* @file mk_fat_utils_readCache.c
* @brief Définition de la fonction mk_fat_utils_readCache.
* @date 7 janv. 2021
*
*/

#include "mk_file_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_fat_utils_readCache ( T_mkFile* p_file, uint64_t p_blockAddress )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'une variable contenant le nombre d'octets lus dans le secteur */
   uint64_t l_numberOfBytesRead = 0;

   /* Déclaration d'une variable de travail */
   uint64_t l_offset = 0;

   /* Réinitialisation de l'adresse du cache */
   p_file->buf = ( uint8_t* ) p_file->cacheBaseAddress;

   /* Si le secteur à lire est déjà présent dans le cache */
   if ( ( p_blockAddress >= p_file->cacheCurrentAddress ) &&
        ( p_blockAddress < ( p_file->cacheCurrentAddress + p_file->volume->partition.fat.numberOfBlocksPerWindow ) ) )
   {
      /* Détermination de l'offset du secteur à renvoyer */
      l_offset = ( uint64_t ) ( p_blockAddress - p_file->cacheCurrentAddress );

      /* Configuration du pointeur */
      p_file->buf = ( uint8_t* ) ( p_file->buf + ( l_offset * p_file->volume->partition.fat.bytesPerSector ) );
   }

   /* Sinon */
   else
   {
      /* Si nécessaire, écriture du groupe de secteurs présents dans le cache sur le disque */
      l_result = mk_fat_utils_sync ( p_file );

      /* Si aucune erreur ne s'est produite */
      if ( l_result == K_MK_OK )
      {
         /* Lecture d'un groupe de secteurs sur le disque */
         l_result = mk_disk_read ( ( T_mkDisk* ) p_file->volume->disk, p_blockAddress, p_file->buf, p_file->volume->partition.fat.numberOfBlocksPerWindow, &l_numberOfBytesRead );

         /* Si une erreur s'est produite */
         if ( ( l_result != K_MK_OK ) || ( l_numberOfBytesRead != ( p_file->volume->partition.fat.numberOfBlocksPerWindow * p_file->volume->partition.fat.bytesPerSector ) ) )
         {
            /* Actualisation de la variable de retour */
            l_result = K_MK_ERROR_COMM;
         }

         /* Sinon */
         else
         {
            /* Actualisation de l'adresse du cache */
            p_file->cacheCurrentAddress = ( uint32_t ) p_blockAddress;
         }
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }
   }

   /* Retour */
   return ( l_result );
}


