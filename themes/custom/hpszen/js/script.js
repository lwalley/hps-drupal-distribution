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

      if (Drupal.settings.hpszen === undefined) {
        Drupal.settings.hpszen = {};
      }

      // Navigation behaviours include showing/hiding entire navigation on
      // smaller screens and hiding/showing sub navigation menus.
      $('#navigation', context).once('hpszen', function () {

        if (Drupal.settings.hpszen.navigationBreakpoint === undefined) {
          Drupal.settings.hpszen.navigationBreakpoint = 699;
        }

        Drupal.theme.prototype.hpszenToggleSubnavigationClosed = function () {
          return Drupal.t('Open');
        };

        Drupal.theme.prototype.hpszenToggleSubnavigationOpen = function () {
          return Drupal.t('Close');
        };

        Drupal.theme.prototype.hpszenToggleSubnavigationTrigger = function () {
          return '<a href="#" class="subnavigation__toggle" title="' +
                 Drupal.t("Javascript trigger to add or remove sub navigation from the visual display.") +
                 '">' + Drupal.theme('hpszenToggleSubnavigationClosed') + '</a>';
        };

        Drupal.theme.prototype.hpszenToggleNavigationTrigger = function () {
          return '<a class="navigation__toggle" href="#">' + Drupal.t("Menu") + '</a>';
        };

        function toggleNavigation(event) {
          event.preventDefault();
          event.stopPropagation();
          var toggle = this,
              menu   = (event.data.menu instanceof Array) ? event.data.menu[0] : event.data.menu;
          $(menu).toggleClass('element-invisible');

          if (event.data.title) {
            $(event.data.title).toggleClass('expanded');
          };

        }

        function toggleSubnavigation(event) {
          event.preventDefault();
          event.stopPropagation();
          var toggle = this,
              menu   = (event.data.menu instanceof Array) ? event.data.menu[0] : event.data.menu;
              ul     = $(toggle).closest('ul');
          $(menu).toggleClass('element-invisible');

          if ($(menu).hasClass('element-invisible')) {
            $(toggle).html(Drupal.theme('hpszenToggleSubnavigationClosed'));
          } else {
            $(toggle).html(Drupal.theme('hpszenToggleSubnavigationOpen'));
            // If we just opened the submenu of a root item then close any of its siblings' open menus
            if ($(ul).parent().get(0).tagName != 'LI') {
              $(menu).closest('li').siblings().find('> ul:not(.element-invisible)').siblings('a.subnavigation__toggle').trigger('click');
            }
          }
          if (event.data.title) {
            $(event.data.title).toggleClass('expanded');
          };
        }

        // Begin default behaviour on page load.
        navigation = $(this);
        // Show or hide sub navigation if dropdown behaviour is enabled.
        navigation.find('.navigation__block--dropdown li.expanded').each(function () {
          var li = $(this);
          // Add show/hide toggle trigger to all navigation items that have
          // children. Includes nested items.
          li.prepend(Drupal.theme('hpszenToggleSubnavigationTrigger'));
          li.find('a.subnavigation__toggle').bind('click', { menu: $(this).find('> ul') }, toggleSubnavigation);
        });

        // Hide navigation and show toggle for smaller screen widths.
        navigation.once('adjustnavigation', function () {
          var nav = $(this);
          // Conditional must match the media query threshold for horizontal menu in CSS
          if ($(document).width() < Drupal.settings.hpszen.navigationBreakpoint) {
            // Convert navigation to vertical toggle menu
            nav.addClass('navigation__toggle');
            nav.find('.block-menu').each(function () {

              var menuBlock           = $(this),
                  title               = menuBlock.find('> h2')[0],
                  rootMenu            = menuBlock.find('> ul')[0],
                  itemsWithSubmenus   = menuBlock.find('li.expanded');

              // Add link to navigation title and bind show hide toggle
              $(title).wrapInner('<a href="#" />')
              .find('a').bind('click', {menu: rootMenu, title: title}, toggleNavigation);
              // Hide navigation on small screen widths.
              $(rootMenu).addClass('element-invisible');
            });
          }
          else {
            // Show navigation on larger screen widths.
            nav.find('.block-menu > ul').removeClass('element-invisible');
          }
        })

        // Trigger navigation adjustment on load and if screen width changes
        $(window).bind('load resize orientationchange', function () {
          $('#navigation').trigger('adjustnavigation');
        });

      });

      // Slideshow
      // @note To trigger slideshow behaviour add class 'slides' to Views HTML
      //       list, with optional class 'with-pager' to trigger pager
      $('.slides', context).once('hpszen', function () {

        // Only continue if jQuery cycle function is available.
        if ('cycle' in $.fn) {

          Drupal.theme.prototype.hpszenCyclingPagerMarkers = function () {
            return '<div class="slideshow__pager--markers"></div>';
          };
          Drupal.theme.prototype.hpszenCyclingPagerThumbnails = function () {
            return '<div class="slideshow__pager--thumbnails"></div>';
          };
          Drupal.theme.prototype.hpszenCyclingNavigation = function () {
            return '<div class="slideshow__navigation">' +
                   '  <a href="#" title="' +
                      Drupal.t("Visually display the previous slide.") +
                      '" class="slideshow__navigation__previous">' +
                      Drupal.t('Previous slide') + '</a>' +
                   '  <a href="#" title="' +
                      Drupal.t("Pause automated scrolling of slides.") +
                      '" class="slideshow__navigation__pause">' +
                      Drupal.t('Pause slide show') + '</a>' +
                   '  <a href="#" title="' +
                      Drupal.t("Resume automated scrolling of slides.") +
                      '" class="slideshow__navigation__resume">' +
                      Drupal.t('Resume slide show') + '</a>' +
                   '  <a href="#" title="' +
                      Drupal.t("Visually display the next slide.") +
                      '" class="slideshow__navigation__next">' +
                      Drupal.t('Next slide') + '</a>' +
                   '</div>';
          };
          Drupal.theme.prototype.hpszenCyclingPagerMarker = function (index, slide) {
            var slide = $(slide),
                slide_number = index + 1,
                slide_title = slide.find('> h2').text();
            return '<a title="'
              + Drupal.t('Visually display slide @slide_number.', {'@slide_number': slide_number})
              + '" href="#">'
              + Drupal.t('Slide: @slide_title_or_number', { '@slide_title_or_number': slide_title || slide_number })
              + '</a>';
          };
          Drupal.theme.prototype.hpszenCyclingPagerThumbnail = function (index, slide) {
            var slide = $(slide),
                alt = slide.find('> p').text() || '',
                image = slide.find('> span img');
            return '<a title="' + Drupal.t('Slide number @index.', { '@index': index + 1 }) + '" href="#"><img src="' + image.attr('src') + '" alt="' + alt + '"/></a>';
          };

          function pagerMarker(index, slide) {
            return Drupal.theme('hpszenCyclingPagerMarker', index, slide);
          }
          function pagerThumbnail(index, slide) {
            return Drupal.theme('hpszenCyclingPagerThumbnail', index, slide);
          }

          // Called on image load, window resize and after slide transition.
          function positionImage(image) {
            return; // Do nothing because this looks rubbish and doesn't work properly.
            // @todo Idea is to reposition image to show more of center content
            //       on drastic crops. At the moment image widths are at 100%
            //       and cropping is handled by CSS, so this incorrectly spans
            //       up then down. It would be nicer if this could include a
            //       diagonal transition with a zoom as an enhancement to the
            //       CSS crop.
            var container = $(image).closest('span'),
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
            $(image).animate({ 'margin-top': Math.floor(margin) + 'px'}, 10000);
          }

          var slides = $(this),
              images = $(this).find('> li > span img');

          slides.closest('div').addClass('slideshow--cycling');

          images.one('load', function () {
            positionImage(this);
          }).each(function () {
            if (this.complete) $(this).load();
          });

          cycle_options = {
            prev: '.slideshow__navigation__previous',
            next: '.slideshow__navigation__next',
            pause: 1,
            speed: 1000,
            fastOnEvent: 200,
            delay: -3000,
            timeout: 15000,
            after: function () {
              positionImage($(this).find('> span img')[0]);
            }
          }

          slides.parent().append(Drupal.theme('hpszenCyclingNavigation'));

          if (slides.hasClass('with-pager-markers')) {
            slides.parent().append(Drupal.theme('hpszenCyclingPagerMarkers'));
            cycle_options.pager = '.slideshow__pager--markers';
            cycle_options.pagerAnchorBuilder = pagerMarker;
          }
          if (slides.hasClass('with-pager-thumbnails')) {
            slides.parent().append(Drupal.theme('hpszenCyclingPagerThumbnails'));
            cycle_options.pager = '.slideshow__pager--thumbnails';
            cycle_options.pagerAnchorBuilder = pagerThumbnail;
          }

          slides.cycle(cycle_options);

          $('.slideshow__navigation__pause').click(function() {
            slides.cycle('pause');
            slides.addClass('slideshow--paused');
            $(this).parent().addClass('slideshow--paused');
            event.preventDefault();
            event.stopPropagation();
          });
          $('.slideshow__navigation__resume').click(function() {
            slides.removeClass('slideshow--paused');
            $(this).parent().removeClass('slideshow--paused');
            slides.cycle('resume');
            event.preventDefault();
            event.stopPropagation();
          });

          $(window).bind('resize', function () {
            slides.each(function () {
              $(this).width($(this).closest('div').width());
              positionImage($(this).find('> span img')[0]);
            });
          });
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);
