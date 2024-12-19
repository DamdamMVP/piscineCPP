/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:51:52 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 04:26:39 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook
{
  private:
	Contact contacts[8];
	int index;
	int contactCount;
	void drawContacts() const;
	void drawFullInfo() const;

  public:
	PhoneBook();
	void addContact();
	void searchContact() const;
};
