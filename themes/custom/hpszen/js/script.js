/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.hpszen = {
    attach: function (context, settings) {

      // Primary navigation menu
      $('#navigation', context).once('hpszen', function () {

        Drupal.theme.hpszenSubmenuToggle = function () {
          return '<a href="#" class="submenu-toggle" title="' +
                 Drupal.t("Javascript trigger to add or remove this item's " +
                          "submenu from the visual display.") +
                 '">&or;</a>';
        };

        Drupal.theme.hpszenToggleMenuTrigger = function () {
          return '<a class="menu-toggle" href="#">' + Drupal.t('Menu') + '</a>';
        };

        $(this).find('ul').addClass('element-invisible');
        $(this).find('li.expanded').each(function () {
          var li = $(this);
          li.prepend(Drupal.theme('hpszenSubmenuToggle'));
          li.find('a.submenu-toggle').bind('click', { menu: $(this).find('> ul') }, toggleMenu);
        });

        $(this).once('adjustnavigation', function () {
          var nav = $(this);
          if (nav.width() < 600) {
            // Convert navigation to vertical toggle menu
            nav.addClass('toggle-menu');
            nav.find('.block-menu').each(function () {

              var menuBlock           = $(this),
                  title               = menuBlock.find('> h2')[0],
                  rootMenu            = menuBlock.find('> ul')[0],
                  itemsWithSubmenus   = menuBlock.find('li.expanded');

              // Add link to title and bind click event to it for main menu toggle
              $(title).wrapInner('<a href="#" />')
              .find('a').bind('click', {menu: rootMenu}, toggleMenu);

            });
          }
          else {
            // Show root menu
            nav.find('.block-menu > ul').removeClass('element-invisible');
          }
        })

        $(window).bind('load resize orientationchange', function () {
          $('#navigation').trigger('adjustnavigation');
        });

        function toggleMenu(event) {
          event.preventDefault();
          event.stopPropagation();
          $(event.data.menu).toggleClass('element-invisible');
        }
      });

      // Slideshow
      $('.slides', context).once('hpszen', function () {

        if ("cycle" in $.fn) {

          Drupal.theme.hpszenCyclingPager = function () {
            return '<div class="pager"></div>';
          };

          Drupal.theme.hpszenCyclingPagerItem = function (index, slide) {
            var slide = $(slide),
                alt = slide.find('h2').text() || '',
                image = slide.find('.field-type-image img');
            return '<a title="' + Drupal.t('Slide number @index.', { '@index': index + 1 }) + '" href="#"><img src="' + image.attr('src') + '" alt="' + alt + '"/></a>';
          };

          // Assumes slides are in .view-content:
          var slides = $(this),
              images = $(this).find('.field-type-image img');
          slides.closest('.view-content').addClass('cycling');

          images.one('load', function () {
            positionImage(this);
          }).each(function () {
            if (this.complete) $(this).load();
          });

          slides.parent().append(Drupal.theme('hpszenCyclingPager'));

          slides.cycle({
            pager:  '.pager',
            pagerAnchorBuilder: pagerItem,
            pause: 1,
            speed: 1000,
            fastOnEvent: 200,
            delay: -2000,
            timeout: 15000,
            fx: 'scrollLeft',
            after: function () {
              positionImage($(this).find('.field-type-image img')[0]);
            }
          });

          function pagerItem(index, slide) {
            return Drupal.theme('hpszenCyclingPagerItem', index, slide);
          }

          $(window).bind('resize', function () {
            slides.each(function () {
              $(this).width($(this).closest('.view-content').width());
              positionImage($(this).find('.field-type-image img')[0]);
            });
          });

          // Called on image load, window resize and after slide transition.
          function positionImage(image) {
            var container = $(image).closest('.field-type-image'),
                showing = (container.height() / image.height),
                margin  = 0;
            if (!container.width() > 0 || !image.width > 0) return; // Stop if slide hidden
            switch (true) {
              case showing < 0.3:
                margin = (image.height * -0.3);
                break;
              case showing < 0.4:
                margin = (image.height * -0.2);
                break;
              case showing < 0.5:
                margin = (image.height * -0.14);
                break;
              case showing < 0.6:
                margin = (image.height * -0.09);
                break;
              default:
                // Most of the image is showing, do nothing
            }
            $(image).css('margin-top', Math.floor(margin) + 'px');
          }
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);
